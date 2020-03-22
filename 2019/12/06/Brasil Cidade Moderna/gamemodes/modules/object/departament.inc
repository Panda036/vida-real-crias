#include YSI\y_hooks

new PoliceGate[2];

hook OnGameModeInit()
{
    PoliceGate[0] = CreateObject(19302, 246.39900, 72.49900, 1003.85809, 0.00000, 0.00000, 0.00000);// 246.39900, 72.49900, 1007.10938
    PoliceGate[1] = CreateObject(19302, 250.49590, 63.33670, 1003.84442, 0.00000, 0.00000, 90.00000);//250.49590, 63.33670, 1006.37250
    return 1;
}

OpeningPolicePort(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.39900, 72.49900, 1003.85809))
    {
        MoveObject(PoliceGate[0], 246.39900, 72.49900, 1007.10938, 3.0);
        SetTimer("ClosingPolicePort", 1000*5, false);
        SendClientMessage(playerid, 0x00C40AAA, "| INFO | O Portão do Departamento de Policia foi aberto e fechara em 5 segundos");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 250.49590, 63.33670, 1003.84442))
    {
        MoveObject(PoliceGate[1], 250.49590, 63.33670, 1006.37250, 3.0);
        SetTimer("ClosingPolicePort1", 1000*5, false);
        SendClientMessage(playerid, 0x00C40AAA, "| INFO | O Portão do Departamento de Policia foi aberto e fechara em 5 segundos");
    }
    return 1;
}

forward ClosingPolicePort();
public ClosingPolicePort()
{
    MoveObject(PoliceGate[0], 246.39900,72.49900,1003.85809,3.0);
    return 1;
}

forward ClosingPolicePort1();
public ClosingPolicePort1()
{
    MoveObject(PoliceGate[1], 250.49590, 63.33670, 1003.84442, 3.0);
    return 1;
}
