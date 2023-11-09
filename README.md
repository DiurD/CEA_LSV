# CEA_LSV
Repositório para arquivos utilizados no Simulador de Voo do Laboratório de Simulação de Voo (LSV) do Centro de Estudos Aeronáuticos (CEA) na UFMG.

## Sumário
1. [Informações Gerais](#informações-gerais)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Collaboration](#collaboration)
5. [FAQs](#faqs)

## Informações Gerais

Projeto *open source* do desenvolvimento de um simulador de voo voltado para aplicação no Laboratório de Simulação de Voo (LSV) do Centro de Estudos Aeronáuticos (CEA) da Universidade Federal de Minas Gerais (UFMG). O projeto consiste na simulação da mecânica de voo de uma aeronave no ambiente *Matlab* e *Simulink* para transmissão dos dados de posição e atitude para o *software* *XPlane 11*, com objetivos de uma possível implementação de um simulador físico funcional e aplicação das teorias de controle durante o voo da aeronave. 

No atual estado, o *software* desenvolvido no ambiente *Matlab* só é capaz de simular uma aeronave em voo de cruzeiro, visto que simular o pouso e decolagem no programa envolveria coletar dados em tempo real do nível do solo, realizando a comparação constante com a altitude da aeronave, além de necessitar de dados adicionais que ainda não foram inseridos como o tamanho do trem de pouso para deslocamento do cockpit acima do solo. Na estrutura atual, a simulação ocorre apenas em uma via *Simulink*->*XPlane 11*, causando um erro fatal caso a aeronave no ambiente *Simulink* se encontre abaixo do nível do solo do *XPlane*. O usuário deve definir as características físicas e de estabilidade da aeronave a ser simulada e por enquanto somente os dados da aeronave *Cessna 182* foram itroduzidos.

A execução deve ser realizada **na seguinte ordem** dentro do diretório "CEA_LSV\CEA_LSV Matlab and Simulink files":

1. Executar o *XPlane 11* e decolar a aeronave (qualquer modelo de aeronave pois esta sera sobrescrita na simulação do simulink);
2. Com a aeronave em cruzeiro, executar o *plugin* desenvolvido dentro do *XPlane 11* e clicar na caixa para desabilitar a física do jogo. Nete momento, a aeronave permanecerá estática no ar;
3. Inicializar dados da gravidade e dados físicos da aeronave no ambiente *Matlab* ao executar a primeira seção do arquivo `Initiate_Aircraft.m`. O usuário pode trocar a aeronave de simulação por qualquer aeronave presente no diretório "CEA_LSV\CEA_LSV Matlab and Simulink files\Aircrafts";
4. Executar a segunda parte do arquivo `Initiate_Aircraft.m` para capturar os dados de velocidade, posição e atitude da aeronave no momento do Item 2;
5. Abrir (sem executar) o arquivo `Initiate_Simulation.slx` assim como todos os arquivos de biblioteca do tipo ".slx" dentro do diretório "CEA_LSV\CEA_LSV Matlab and Simulink files\Library";
6. Dentro do *XPlane 11* habilitar a caixa de seleção do *plugin* para comunicação do *XPlane* com o *Simulink* e em seguida executar o arquivo `Initiate_Simulation.slx`
   - Caso a caixa de seleção seja ativada e o código `Initiate_Simulation.slx` não for executado, o *XPlane* congelará até que seja feita a execução. O usuário pode escolher por encerrar o programa de visualização do estado da aeronave à força caso deseje encerrar e voltar ao Item 1.
7. Para encerrar a execução, desabilite a caixa de seleção do Item 6 e encerre a simulação do *Simulink*. Após a caixa de seleção do *plugin* ser desativada, a aeronave voltará a ser simulada com a física presente no jogo, sendo necessário a reativação da caixa de retirar a física do jogo caso o usuário deseje.


## Pastas presentes no repositório
* On first install: Version 12.3 
* [Technology name](https://example.com): Version 2.34
* [Library name](https://example.com): Version 1234
