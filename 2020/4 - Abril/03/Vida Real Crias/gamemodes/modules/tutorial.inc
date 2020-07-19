#include YSI\y_hooks

new TutorialTimer[MAX_PLAYERS][12];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new timerid = 0; timerid < 12; timerid++)
    {
        KillTimer(TutorialTimer[playerid][timerid]);
    }

    PlayerInfo[playerid][tutorial] = 0;
    TogglePlayerSpectating(playerid, false);
    HideTDTutorial(playerid);
    return 1;
}

forward LoadTutorial(playerid);
public LoadTutorial(playerid)
{
    if(cache_num_rows())
    {
        TogglePlayerSpectating(playerid, true);
        InterpolateCameraPos(playerid, 1160.0197, -1551.2655, 39.6697, 1150.1077, -1706.8904, 36.3631, 15000);
        InterpolateCameraLookAt(playerid, 1159.9934, -1552.2712, 39.3047, 1150.1094, -1707.8959, 35.9081, 15000);

        ShowTDTutorial(playerid, "~r~AgŸncia_de_Empregos~n~~w~A_agŸncia_de_emprego_existe_com_um_objetivo_simples,~n~conectar_os_desempregados_com_alguma_profissšo.~n~Assim_como_qualquer_outro_local_publico,_ela_fica_localizada_no_~r~/gps.");
        TutorialTimer[playerid][0] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 1);
    }
    else
    {
        TDShowHourDate(playerid);
        StatusMostrar(playerid);

        format(String, sizeof(String), "%d", PlayerInfo[playerid][Estrelas]);
        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], String);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][1]);
    }
    return 1;
}

forward OnPlayerTutorial(playerid, value);
public OnPlayerTutorial(playerid, value)
{
    switch(value)
    {
        case 1:
        {
            InterpolateCameraPos(playerid, 1407.3717, -1612.3888, 72.2927, 1501.2203, -1652.8976, 32.0717, 15000);
            InterpolateCameraLookAt(playerid, 1408.2942, -1612.7924, 71.7226, 1502.1586, -1653.2627, 31.6316, 15000);

            ShowTDTutorial(playerid, "~r~Departamento_de_Pol¢cia~n~~w~Como_o_pr¦prio_nome_diz,_ž_um_Departamento_de_Pol¢cia.~n~A onde_os_Pol¢cias_se_equipam_e_se_preparam_para_combater_a_ilegalidade.");
            TutorialTimer[playerid][1] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 2);
        }
        case 2:
        {
            InterpolateCameraPos(playerid, 1457.7594, -1628.5387, 54.6636, 1480.7886, -1730.1342, 22.1651, 15000);
            InterpolateCameraLookAt(playerid, 1457.9960, -1629.5162, 54.2036, 1480.8877, -1731.1353, 21.9400, 15000);

            ShowTDTutorial(playerid, "~r~Prefeitura~n~~w~A_Prefeitura_tem_algumas_funœoes_que_tras_a_melhoria_para_o_servidor.");
            TutorialTimer[playerid][2] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 3);
        }
        case 3:
        {
            InterpolateCameraPos(playerid, 1684.4171, -1749.6566, 53.1859, 1742.7949, -1695.0062, 28.3228, 15000);
            InterpolateCameraLookAt(playerid, 1685.1587, -1748.9744, 52.6609, 1743.5052, -1694.2916, 27.9177, 15000);

            ShowTDTutorial(playerid, "~r~Banco~n~~w~O_Banco_ž_uma_instituiœšo_financeira~n~que_administra_o_dinheiro_que_seus_clientes_deixam_em_cust¦dia.");
            TutorialTimer[playerid][3] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 4);
        }
        case 4:
        {
            InterpolateCameraPos(playerid, 2120.9358, 2204.5503, 57.3285, 2155.8298, 2266.6245, 21.5121, 15000);
            InterpolateCameraLookAt(playerid, 2121.4734, 2205.3911, 56.6535, 2156.4714, 2267.3882, 21.1921, 15000);

            ShowTDTutorial(playerid, "~r~Auto_Escola~n~~w~Centro_de_formaœšo_de_Condutores_de_ve¢culo(s).");
            TutorialTimer[playerid][4] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 5);
        }
        case 5:
        {
            InterpolateCameraPos(playerid, -2635.6287, 119.9039, 21.5684, -2690.6216, 125.0409, 11.7221, 15000);
            InterpolateCameraLookAt(playerid, -2636.6248, 119.9797, 21.2985, -2691.6177, 125.1188, 11.5072, 15000);

            ShowTDTutorial(playerid, "~r~Detran~n~~w~Departamento_de_Tr™nsito_do_Vida_Real_Crias.~n~Aqui_vocŸ_paga_sua(s)_multa(s)_pendente(s).");
            TutorialTimer[playerid][5] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 6);
        }
        case 6:
        {
            InterpolateCameraPos(playerid, -2735.2478, 47.6116, 38.6107, -2687.0881, 11.9669, 10.3945, 15000);
            InterpolateCameraLookAt(playerid, -2734.4624, 46.9966, 38.1107, -2686.2466, 11.4317, 10.1346, 15000);

            ShowTDTutorial(playerid, "~r~Area_VIP~n~~w~Aqui_pode_equipar_armas_gratis.~n~Mais_um_dos_privilžgio_VIP_que_temos_em_nosso_servidor.~n~Para_saber_mais_digite_~r~/VantagensVip_~w~ap¦s_completar_o_tutorial.");
            TutorialTimer[playerid][6] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 7);
        }
        case 7:
        {
            InterpolateCameraPos(playerid, 491.4691, -1269.2939, 39.7747, 542.7042, -1225.9427, 39.7747, 15000);
            InterpolateCameraLookAt(playerid, 492.3849, -1269.6921, 39.2148, 542.8288, -1226.9336, 39.2398, 15000);

            ShowTDTutorial(playerid, "~r~Concessionaria~n~~w~Na_Concessionaria_vocŸ_encontra_ve¢culos_para_compra.");
            TutorialTimer[playerid][7] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 8);
        }
        case 8:
        {
            InterpolateCameraPos(playerid, 2509.1626, 1186.6383, 61.4503, 2445.7581, 1095.9176, 27.1042, 15000);
            InterpolateCameraLookAt(playerid, 2508.2458, 1186.2424, 60.8303, 2444.9226, 1096.4637, 26.5841, 15000);

            ShowTDTutorial(playerid, "~r~Imobiliaria~n~~w~Aqui_vocŸ_pode_ser_encaminhado_para_compra_de_uma_casa/empresa.");
            TutorialTimer[playerid][8] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 9);
        }
        case 9:
        {
            InterpolateCameraPos(playerid, 2024.7410, -1422.9026, 21.0261, 1982.2883, -1478.3285, 53.4862, 15000);
            InterpolateCameraLookAt(playerid, 2025.2797, -1422.0623, 20.5761, 1982.9117, -1477.5483, 52.9962, 15000);

            ShowTDTutorial(playerid, "~r~Hospital~n~~w~Hospital_ž_destinado_ao_atendimento_de_doentes.~n~Faœa_o_Plano_de_Saude_para_nšo_perder_dinheiro.");
            TutorialTimer[playerid][9] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 10);
        }
        case 10:
        {
            InterpolateCameraPos(playerid, 1080.7759, 1791.8442, 42.5971, 1097.9108, 1635.5487, 20.0955, 15000);
            InterpolateCameraLookAt(playerid, 1080.8947, 1790.8538, 42.2470, 1097.9626, 1634.5530, 19.8855, 15000);

            ShowTDTutorial(playerid, "~r~Arena~n~~w~Na_arena_vocŸ_pode_~g~matar~w~/~r~morrer~w~_sem_receber_estrelas.");
            TutorialTimer[playerid][10] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 11);
        }
        case 11:
        {
            InterpolateCameraPos(playerid, 666.9689, -1182.8660, 66.4762, 816.2747, -1343.7556, 13.5289, 15000);
            InterpolateCameraLookAt(playerid, 666.10689, -1181.8660, 66.1762, 816.2747, -1343.7556, 13.5289, 15000);

            ShowTDTutorial(playerid, "~r~Final_do_Tutorial~n~~w~Chegamos_ao_fim._Espero_que_tenha_retirado_todas_as_suas_duvidas,~n~se_nšo_tirou,_digite_~r~/ajuda~w~_ou_~r~/duvida~w~_ap¦s_completar_o_tutorial.");
            TutorialTimer[playerid][11] = SetTimerEx("OnPlayerTutorial", 15000, false, "dd", playerid, 0);
        }
        default:
        {
            PlayerInfo[playerid][tutorial] = 0;
            TogglePlayerSpectating(playerid, false);
            SaveAccounts(playerid);
            HideTDTutorial(playerid);
            TDShowHourDate(playerid);
            StatusMostrar(playerid);

            format(String, sizeof(String), "%d", PlayerInfo[playerid][Estrelas]);
            PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], String);
            PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][1]);

            new query[200];
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `Contas` SET `Tutorial`='%d' WHERE `id`='%d'", PlayerInfo[playerid][tutorial], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);
        }
    }
    return 1;
}
