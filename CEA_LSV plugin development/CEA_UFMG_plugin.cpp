

// CEA Widget
#include "XPLMPlugin.h"
#include "XPLMDisplay.h"
#include "XPLMGraphics.h"
#include "XPLMProcessing.h"
#include "XPLMMenus.h"
#include "XPLMUtilities.h"
#include "XPWidgets.h"
#include "XPStandardWidgets.h"
#include "XPLMDataAccess.h"
#include "XPLMCamera.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#if IBM
#include <windows.h>
#endif
#include <vector>

// UDP Packets

#pragma comment (lib, "ws2_32")
#pragma comment (lib, "wsock32.lib")
#pragma comment (lib, "wsock32")
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>            // For cout and cerr
#include "PracticalSocket.h"


#if APL
#if defined(__MACH__)
#include <Carbon/Carbon.h>
#endif
#endif

static bool listening4UDP;
#define UDP_PORT_RECEIVE 49003
#define UDP_RECEIVE_DELTA_T 0.017
const int MAXRCVSTRING = 4096;

#define MAX_ITEMS 11

static XPLMDataRef gPositionDataRef[MAX_ITEMS];

static char DataRefString[MAX_ITEMS][255] = { "sim/flightmodel/position/local_x", "sim/flightmodel/position/local_y", "sim/flightmodel/position/local_z",
										"sim/flightmodel/position/lat_ref", "sim/flightmodel/position/lon_ref",	"sim/flightmodel/position/theta",
										"sim/flightmodel/position/phi", "sim/flightmodel/position/psi",
										"sim/flightmodel/position/latitude", "sim/flightmodel/position/longitude", "sim/flightmodel/position/elevation" };

static int	Element = 0, IntVals[128];
static float FloatVals[128];
static int ByteVals[128];

#define NUMBER_OF_OVERRIDES 1

static int MenuItem1;

static XPWidgetID UFMGWidget = NULL, UFMGPanel = NULL;// UFMGPreviousButton = NULL, UFMGNextButton = NULL;
static XPWidgetID UFMGEdit[2] = {NULL};
static XPWidgetID UFMGCheckBox[2] = {NULL};

static char DataRefGroup[] = "sim/operation/override/";
static char DataRefDesc[NUMBER_OF_OVERRIDES][40] = {"override_planepath"};

static char ButtonsDesc[2][255] = {"Disable Physics Engine","Activate MatLab Communication"};

static int NumberOfOptions, UFMGScreenNumber, MaxScreenNumber;
typedef	std::vector<XPLMDataRef> aXPLMDataRefID;

static aXPLMDataRefID DataRefID;
static XPLMDataRef gSpecialDataRef;


static float	MyFlightLoopCallback(
	float                inElapsedSinceLastCall,
	float                inElapsedTimeSinceLastFlightLoop,
	int                  inCounter,
	void* inRefcon);

static void ApplyPosition(double X, double Y, double Z);
static void ApplyRotation(float theta, float phi, float psi);
// // // // //



static void UFMGEngineMenuHandler(void *, void *);
static void CreateCEAPlugin(int x1, int y1, int w, int h);
static int UFMGHandler(
						XPWidgetMessage			inMessage,
						XPWidgetID				inWidget,
						intptr_t				inParam1,
						intptr_t				inParam2);
static void RefreshCEAPlugin(void);
static void GetDataRefIds(void);

static int GetDataRefState(XPLMDataRef DataRefID);
static void SetDataRefState(XPLMDataRef DataRefID, int State);

PLUGIN_API int XPluginStart(
						char *		outName,
						char *		outSig,
						char *		outDesc)
{
/*	char outputPath[255];
	#if APL && __MACH__
	char outputPath2[255];
	int Result = 0;
	#endif */


	XPLMMenuID	id;
	int			item;

	strcpy(outName, "CEA Plugin");
	strcpy(outSig, "UFMG.CEA.plugin");
	strcpy(outDesc, "A plugin that disables internal XPlane Physhics engine, listens and pass UDP packets");

	item = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "CEA Xplane Plugin", NULL, 1);

	id = XPLMCreateMenu("CEA Plugin", XPLMFindPluginsMenu(), item, UFMGEngineMenuHandler, NULL);

	XPLMAppendMenuItem(id, "Enable/Disable CEA Plugin", (void *) "EnableDisableCEAPlugin", 1);

	MenuItem1 = 0;

	for (int Item = 0; Item < MAX_ITEMS; Item++)
		gPositionDataRef[Item] = XPLMFindDataRef(DataRefString[Item]);

	return 1;
}

PLUGIN_API void	XPluginStop(void)
{
	if (MenuItem1 == 1)
	{
		XPDestroyWidget(UFMGWidget, 1);
		MenuItem1 = 0;
	}
}

PLUGIN_API void XPluginDisable(void)
{
}

PLUGIN_API int XPluginEnable(void)
{
	return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void * inParam)
{
}

float OverrideLoopCB(float elapsedMe, float elapsedSim, int counter, void * refcon)
{
	return 1;
}

void UFMGEngineMenuHandler(void * mRef, void * iRef)
{
	if (!strcmp((char *) iRef, "EnableDisableCEAPlugin"))
	{
		if (MenuItem1 == 0)
		{
			UFMGScreenNumber = 0;
			CreateCEAPlugin(300, 550, 350, 380);
			MenuItem1 = 1;
		}
		else
			if(!XPIsWidgetVisible(UFMGWidget))
				XPShowWidget(UFMGWidget);
	}
}


void CreateCEAPlugin(int x, int y, int w, int h)
{
	int x2 = x + w;
	int y2 = y - h;
	int Item;
	int WindowCentre = x+w/2;
	int yOffset;
	char Buffer[255];

	DataRefID.clear();
	memset(UFMGCheckBox, 0, sizeof(UFMGCheckBox));
	
	GetDataRefIds();


	listening4UDP = FALSE;
	float FloatValue[MAX_ITEMS];
	for (Item = 0; Item < MAX_ITEMS; Item++)
		FloatValue[Item] = XPLMGetDataf(gPositionDataRef[Item]);
	


	UFMGWidget = XPCreateWidget(x, y, x2, y2,
					1, "CEA Plugin", 1, NULL,
					xpWidgetClass_MainWindow);

	XPSetWidgetProperty(UFMGWidget, xpProperty_MainWindowHasCloseBoxes, 1);

	UFMGPanel = XPCreateWidget(x+50, y-50, x2-50, y2+50,
					1, "", 0, UFMGWidget,
					xpWidgetClass_SubWindow);

	XPSetWidgetProperty(UFMGPanel, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);


	/*UFMGPreviousButton = XPCreateWidget(WindowCentre - 80, y2 + 24, WindowCentre - 10, y2 + 2,
					1, "Previous", 0, UFMGWidget,
					xpWidgetClass_Button);

	XPSetWidgetProperty(UFMGPreviousButton, xpProperty_ButtonType, xpPushButton);

	UFMGNextButton = XPCreateWidget(WindowCentre+10, y2+24, WindowCentre+80, y2+2,
					1, "Next", 0, UFMGWidget,
					xpWidgetClass_Button);

	XPSetWidgetProperty(UFMGNextButton, xpProperty_ButtonType, xpPushButton); */

	for (Item=0; Item<2; Item++)
	{
		yOffset = (45+28+(Item*30));
		strcpy(Buffer, "");
		UFMGEdit[Item] = XPCreateWidget(x+60, y-yOffset, x+60+200, y-yOffset-20,
					1, ButtonsDesc[Item], 0, UFMGWidget,
					xpWidgetClass_Caption);
		// XPSetWidgetProperty(UFMGEdit[Item], xpProperty_TextFieldType, xpTextEntryField);
	}

	for (Item=0; Item<2; Item++)
	{
		yOffset = (45+28+(Item*30));
		UFMGCheckBox[Item] = XPCreateWidget(x+260, y-yOffset, x+260+22, y-yOffset-20,
					1, "", 0, UFMGWidget,
					xpWidgetClass_Button);

		XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonType, xpRadioButton);
		XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonBehavior, xpButtonBehaviorCheckBox);
		XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 0);
	}

	RefreshCEAPlugin();

	XPAddWidgetCallback(UFMGWidget, UFMGHandler);
}

int	UFMGHandler(
						XPWidgetMessage			inMessage,
						XPWidgetID				inWidget,
						intptr_t				inParam1,
						intptr_t				inParam2)
{
	int Item, State;

	if (inMessage == xpMessage_CloseButtonPushed)
		{
			if (MenuItem1 == 1)
			{
				XPHideWidget(UFMGWidget);
			}
			return 1;
		}

	/*if (inMessage == xpMsg_PushButtonPressed)
	{
		if (inParam1 == (intptr_t)UFMGPreviousButton)
		{
			UFMGScreenNumber--;
			if (UFMGScreenNumber<0)
				UFMGScreenNumber = 0;
			RefreshCEAPlugin();
			return 1;
		}

		if (inParam1 == (intptr_t)UFMGNextButton)
		{
			UFMGScreenNumber++;
			if (UFMGScreenNumber>MaxScreenNumber)
				UFMGScreenNumber = MaxScreenNumber;
			RefreshCEAPlugin();
			return 1;
		}
	} */

	if (inMessage == xpMsg_ButtonStateChanged)
	{
		for (Item=0; Item<2; Item++)
		{
			if (Item==0)
			{
				State = XPGetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 0);
				SetDataRefState(DataRefID[Item], State);

				if(State)
				{
					XPSetWidgetProperty(UFMGCheckBox[1], xpProperty_Enabled, 1);
				}
				else
				{
					if (XPGetWidgetProperty(UFMGCheckBox[1], xpProperty_ButtonState, 0)) {
						
						listening4UDP = FALSE;
						XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);
						XPSetWidgetProperty(UFMGCheckBox[1], xpProperty_ButtonState, 0);

					}

					XPSetWidgetProperty(UFMGCheckBox[1], xpProperty_Enabled, 0);
				}

			}

			if (inParam1 == (intptr_t)UFMGCheckBox[1])
			{
				State = XPGetWidgetProperty(UFMGCheckBox[1], xpProperty_ButtonState, 0);
				if (State)
				{
					listening4UDP = TRUE;
					XPLMRegisterFlightLoopCallback(MyFlightLoopCallback, UDP_RECEIVE_DELTA_T, NULL);
				}
				else
				{
					listening4UDP = FALSE;
					XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);
				}
				SetDataRefState(DataRefID[0], State);
			}
		} 

	}
	return 0;
}						


void RefreshCEAPlugin(void)
{
	int Item;
	char Buffer[255];
	
	for (Item=0; Item<2; Item++)
	{
		// strcpy(Buffer, "");
		if ((Item+(UFMGScreenNumber*2)) < NumberOfOptions)
		{
			if (Item == 0)
			{
				// XPSetWidgetDescriptor(UFMGEdit[Item], ButtonsDesc[Item+(UFMGScreenNumber*2)]);
				if (GetDataRefState(DataRefID[Item]))
				{
					XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 1);
					XPSetWidgetProperty(UFMGCheckBox[1], xpProperty_Enabled, 1);
				}
				else
				{
					XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 0);
					XPSetWidgetProperty(UFMGCheckBox[1], xpProperty_Enabled, 0);
				}
				XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_Enabled, 1);
			}

			if (Item == 1)
			{
				if (listening4UDP)
				{
					XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 1);	
					
				}
				else
				{
					XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 0);
					
				}				
			}
			
		}
		else
		{
			// XPSetWidgetDescriptor(UFMGEdit[Item], Buffer);
			XPSetWidgetProperty(UFMGCheckBox[Item], xpProperty_ButtonState, 0);
		}
	}
	
	/*if (UFMGScreenNumber == 0)
		XPSetWidgetProperty(UFMGPreviousButton, xpProperty_Enabled, 0);
	else
		XPSetWidgetProperty(UFMGPreviousButton, xpProperty_Enabled, 1);
		XPSetWidgetDescriptor(UFMGPreviousButton, "Previous");

	if (UFMGScreenNumber == MaxScreenNumber)
		XPSetWidgetProperty(UFMGNextButton, xpProperty_Enabled, 0);
	else
		XPSetWidgetProperty(UFMGNextButton, xpProperty_Enabled, 1);	
		XPSetWidgetDescriptor(UFMGNextButton, "Next");*/
}						

void GetDataRefIds(void)
{
	int Item, ItemIndex=0;
	XPLMDataRef TempDataRefID;
	char TempDesc[256];

	NumberOfOptions = NUMBER_OF_OVERRIDES+1;

	for (Item=0; Item<NumberOfOptions-1; Item++)
	{
		strcpy(TempDesc, "sim/operation/override/override_planepath");
		TempDataRefID = XPLMFindDataRef(TempDesc);
		if (Item == 0)
			gSpecialDataRef = TempDataRefID;
		DataRefID.push_back(TempDataRefID);
	}

	MaxScreenNumber = (NumberOfOptions-1) / 2;
}

int GetDataRefState(XPLMDataRef DataRefID)
{
	int	DataRefi, IntVals[8];
	
	memset(IntVals, 0, sizeof(IntVals));
	if (DataRefID == gSpecialDataRef)
	{
		XPLMGetDatavi(DataRefID, IntVals, 0, 8);
		DataRefi = IntVals[0];
	}
	else
		DataRefi = XPLMGetDatai(DataRefID);

	return DataRefi;
}

void SetDataRefState(XPLMDataRef DataRefID, int State)
{
	int	IntVals[8];
	
	memset(IntVals, 0, sizeof(IntVals));
	if (DataRefID == gSpecialDataRef)
	{
		IntVals[0] = State;
		XPLMSetDatavi(DataRefID, IntVals, 0, 8);
	}
	else
		XPLMSetDatai(DataRefID, State);
}

float	MyFlightLoopCallback(
	float                inElapsedSinceLastCall,
	float                inElapsedTimeSinceLastFlightLoop,
	int                  inCounter,
	void* inRefcon)
{
	float elapsed = XPLMGetElapsedTime();

	if (listening4UDP) {
		double phiDegDouble;
		double thetaDegDouble;
		double psiDegDouble;
		double Xmatlab;
		double Ymatlab;
		double Zmatlab;

		float thetaDeg;
		float phiDeg;
		float psiDeg;


		try {
			
			unsigned short echoServPort = UDP_PORT_RECEIVE;

			UDPSocket sock(echoServPort);


			char recvString[MAXRCVSTRING + 1];
			string sourceAddress;
			unsigned short sourcePort;
			int bytesRcvd = sock.recvFrom(recvString, MAXRCVSTRING, sourceAddress, sourcePort);
			recvString[bytesRcvd] = '\0';

			char *pch;
			pch = strtok(recvString, " ");

			for (int wordNumber = 0; wordNumber < 6; wordNumber++)
			{
				double value = atof(pch);

				if (wordNumber == 0) {
					phiDegDouble = value;
				}
				else if (wordNumber == 1) {
					thetaDegDouble = value;
				}
				else if (wordNumber == 2) {
					psiDegDouble = value;
				}
				else if (wordNumber == 3) {
					Xmatlab = value;
				}
				else if (wordNumber == 4) {
					Ymatlab = value;
				}
				else if (wordNumber == 5) {
					Zmatlab = value;
				}
				else {}

				pch = strtok(NULL, " ");
			}

			phiDeg = (float)phiDegDouble;
			thetaDeg = (float)thetaDegDouble;
			psiDeg = (float)psiDegDouble;
		}
		catch (SocketException) { return(1); }

		ApplyRotation(thetaDeg, phiDeg, psiDeg);
		ApplyPosition(Xmatlab, Ymatlab, Zmatlab);
	}
	return UDP_RECEIVE_DELTA_T;
}


void ApplyPosition(double X, double Y, double Z)
{
	XPLMSetDataf(gPositionDataRef[0], X);
	XPLMSetDataf(gPositionDataRef[1], Y);
	XPLMSetDataf(gPositionDataRef[2], Z);

	double latitudeDeg; //Degrees
	double longitudeDeg; //Degrees
	double altitudeMSL; // meters

	XPLMLocalToWorld(X, Y, Z, &latitudeDeg, &longitudeDeg, &altitudeMSL);

	XPLMSetDataf(gPositionDataRef[8], latitudeDeg);
	XPLMSetDataf(gPositionDataRef[9], longitudeDeg);
	XPLMSetDataf(gPositionDataRef[10], altitudeMSL);

}

void ApplyRotation(float theta, float phi, float psi)
{
	XPLMSetDataf(gPositionDataRef[5], theta);
	XPLMSetDataf(gPositionDataRef[6], phi);
	XPLMSetDataf(gPositionDataRef[7], psi);
}
