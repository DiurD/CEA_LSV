# CEA_LSV
Se você consegue ler e entender isto, prossiga para a [seção em português](#pt-br)
If you can read and fully understand English, continue to the [english sections](#en)

## PT-BR
### Sumário
1. [Informações Gerais](#informações-gerais)
2. [Pastas Presentes no Repositório](#pastas-presentes-no-repositório)
3. [Guia de Instalação](#guia-de-instalação)
4. [Ordem de Execução](#ordem-de-execução)


### Informações Gerais

Projeto *open source* do desenvolvimento de um simulador de voo voltado para aplicação no Laboratório de Simulação de Voo (LSV) do Centro de Estudos Aeronáuticos (CEA) na Universidade Federal de Minas Gerais (UFMG). O projeto consiste na simulação da mecânica de voo de uma aeronave no ambiente *Matlab* e *Simulink* com a transmissão dos dados de posição e atitude para o *software* *XPlane 11*, com objetivos de uma possível implementação de um simulador físico funcional e aplicação das teorias de controle durante o voo da aeronave. 

No atual estado, o *software* desenvolvido no ambiente *Matlab* só é capaz de simular uma aeronave em voo de cruzeiro, visto que simular o pouso e decolagem no programa envolveria coletar dados em tempo real do nível do solo no *XPlane*, realizando a comparação constante com a altitude da aeronave no *Simulink*, além de necessitar de dados adicionais que ainda não foram inseridos como o tamanho do trem de pouso para deslocamento do cockpit acima do solo. Na estrutura atual, a simulação ocorre apenas em uma via *Simulink*->*XPlane 11*, causando um erro fatal caso a aeronave no ambiente *Simulink* se encontre abaixo do nível do solo do *XPlane*. O usuário deve definir as características físicas e de estabilidade da aeronave a ser simulada e por enquanto somente os dados da aeronave *Cessna 182* foram itroduzidos.

### Pastas Presentes no Repositório
* **`CEA_LSV Matlab and Simulink files`**: Arquivos *Matlab* (.m) e *Simulink* (.slx) para execução do simulador
* **`CEA_LSV plugin development`**: Arquivos necessários para modificação do *plugin* *CEA_UFMG_plugin* desenvolvido. Cheque a [página oficial](https://developer.x-plane.com/sdk/) para desenolvimento de *plugins* com exemplos que inspiraram a criação do *CEA_UFMG_plugin*
* **`On first install`**: Arquivos necessários para primeira instalação do *software*

### Guia de Instalação

A instalação do simulador de voo é relativamente simples e deve ser seguida como mostrado abaixo, com todos os arquivos presentes na pasta `On first install`:

1. Instale todos os pacotes *Microsoft C++ Redistributables* , localizados em pastas com nomes dos anos em que foram publicados (2005, 2008, 2010, 2012, 2013, 2015)
   - É importante instalar tanto os arquivos x64 quanto os x86
2. Copie a pasta `CEA_UFMG_plugin` para o seguinte diretório "X-Plane 11\Resources\plugins". Caso o *XPlane 11* tenha sido instalado pela *Steam*, é comum ter adicionalmente o seguinte caminho "Program Files\Steam\steamapps\common\X-Plane 11\Resources\plugins"
   - Abra o jogo tente verificar a existência do *plugin*: caso exista, a instalação foi feita com sucesso e você pode prosseguir para a execução; caso não exista, verifique as instalações do Passo 1 ou entre em contato com dmgp1302@gmail.com

### Ordem de Execução

A execução deve ser realizada **na seguinte ordem** dentro do diretório "CEA_LSV\CEA_LSV Matlab and Simulink files":

1. Executar o *XPlane 11* e decolar a aeronave (qualquer modelo de aeronave, pois esta sera sobrescrita na simulação do simulink);
2. Com a aeronave em cruzeiro, executar o *plugin* desenvolvido dentro do *XPlane 11* e clicar na caixa para desabilitar a física do jogo. Nete momento, a aeronave permanecerá estática no ar;
3. Inicializar dados da gravidade e dados físicos da aeronave no ambiente *Matlab* ao executar a primeira seção do arquivo `Initiate_Aircraft.m`. O usuário pode trocar a aeronave de simulação por qualquer aeronave presente no diretório "CEA_LSV\CEA_LSV Matlab and Simulink files\Aircrafts";
4. Executar a segunda parte do arquivo `Initiate_Aircraft.m` para capturar os dados de velocidade, velocidade angular, posição e atitude da aeronave no momento do Item 2;
5. Abrir (sem executar) o arquivo `Initiate_Simulation.slx` assim como todos os arquivos de biblioteca do tipo ".slx" dentro do diretório "CEA_LSV\CEA_LSV Matlab and Simulink files\Library";
6. Dentro do *XPlane 11* habilitar a caixa de seleção do *plugin* para comunicação do *XPlane* com o *Simulink* e em seguida executar o arquivo `Initiate_Simulation.slx`
   - Caso a caixa de seleção seja ativada e o código `Initiate_Simulation.slx` não for executado, o *XPlane* congelará até que seja feita a execução do *Simulink*. O usuário pode escolher por encerrar o programa de visualização do estado da aeronave à força caso deseje encerrar e voltar ao Item 1.
7. Para encerrar a execução, desabilite a caixa de seleção do Item 6 e encerre a simulação do *Simulink*. Após a caixa de seleção do *plugin* ser desativada, a aeronave voltará a ser simulada com a física presente no jogo, sendo necessário a reativação da caixa de retirar a física do jogo caso o usuário deseje.

## EN
1. [General Information](#general-information)
2. [Folders in the Repository](#folders-in-the-repository)
3. [Installation Guide](#installation-guide)
4. [Execution Order](#execution-order)


### General information

An *open source* project of the development of a flight simulator to the Flight Simulation Laboratory (LSV) of the Center of Aeronautical Studies (CEA) at the Federal University of Minas Gerais (UFMG). The project consists in simulating the flight mechanics of an aircraft in the *Matlab* and *Simulink* environment and transmit the position and attitude data to the *software* *XPlane 11*, with objectives of a possible implementation in a physical functional simulator and application of control theories during flight.

In its current state, the *software* developed in the *Matlab* environment is only capable of simulating an aircraft in cruise flight, since simulating landing and takeoff in the program would involve collecting real-time data from ground level in *XPlane*, performing constant comparison with the aircraft's altitude in *Simulink*, in addition to requiring additional data that has not yet been entered, such as the size of the landing gear to dislocate the cockpit above the ground. In the current structure, the simulation is a one-way only *Simulink*->*XPlane 11*, causing a fatal error if the aircraft in the *Simulink* environment is below the *XPlane* ground level. The user must define the physical and stability characteristics of the aircraft to be simulated and for now only data from the *Cessna 182* aircraft has been introduced.

### Folders in the Repository
* **`CEA_LSV Matlab and Simulink files`**: *Matlab* (.m) and *Simulink* (.slx) files for running the simulator
* **`CEA_LSV plugin development`**: Files required to modify the *plugin* *CEA_UFMG_plugin* developed. Check the [official page](https://developer.x-plane.com/sdk/) for *plugin* development with examples that inspired the creation of *CEA_UFMG_plugin*
* **`On first install`**: Files required for the installation of the *software*

### Installation Guide

Installing the flight simulator is relatively simple and must be followed as shown below, with all files present in the `On first install` folder:

1. Install all *Microsoft C++ Redistributables* packages, located in folders named after the years they were published (2005, 2008, 2010, 2012, 2013, 2015)
    - It is important to install both x64 and x86 files
2. Copy the `CEA_UFMG_plugin` folder to the following directory "X-Plane 11\Resources\plugins". If *XPlane 11* was installed by *Steam*, it is common to additionally have the following path "Program Files\Steam\steamapps\common\X-Plane 11\Resources\plugins"
    - Open the game and check the existence of the *plugin*: if found, the installation was successful and you can proceed with to [Execution Order](#execution-order); If not found, verify all instalations in Step 1 or contact dmgp1302@gmail.com

### Execution Order

The execution must be carried out **in the following order** within the "CEA_LSV\CEA_LSV Matlab and Simulink files" directory:

1. Run *XPlane 11* and take off the aircraft (choose any aircraft model, as this will be overwritten in the simulink simulation);
2. With the aircraft in cruise, run the *plugin* developed within *XPlane 11* and click on the box to disable the game's physics. At this moment, the aircraft will remain static in the air;
3. Initialize gravity data and aircraft physics data in the *Matlab* environment by executing the first section of the `Initiate_Aircraft.m` file. The user can change the simulation's aircraft for any aircraft present in the "CEA_LSV\CEA_LSV Matlab and Simulink files\Aircrafts" directory;
4. Execute the second part of the `Initiate_Aircraft.m` file to record the aircraft speed, angular speed, position and attitude data at the time of Item 2;
5. Open (without executing) the file `Initiate_Simulation.slx` as well as all library files of type ".slx" within the directory "CEA_LSV\CEA_LSV Matlab and Simulink files\Library";
6. Within *XPlane 11*, enable the *plugin* check box for *XPlane* communication with *Simulink* and then run the `Initiate_Simulation.slx` file
    - If the check box is activated and the `Initiate_Simulation.slx` code is not executed, *XPlane* will freeze until the execution of the *Simulink* is carried out. The user can choose to forcefully close the game if they wish to exit and return to Item 1.
7. To end the execution, disable the check box in Item 6 and end the *Simulink* simulation. After the *plugin* check box is deactivated, the aircraft will once again be simulated with the physics present in the game, making it necessary to reactivate the box to remove the game's physics if the user wishes.



