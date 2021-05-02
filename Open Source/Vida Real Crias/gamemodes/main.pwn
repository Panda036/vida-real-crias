/************************************************************
* OWNER :
*        Henrique Calenzo
*
* START/END DATE :
*       13/03/2019  -  22/01/2021
*
* NOTES :
*       Copyright Vida Real Crias 2019 - 2021.  All rights free.
*
*/

#define SERVER_SAFETY       false
#define SERVER_OFFLINE      true
#define SERVER_VERSION      "0.5.0"
#define SERVER_IP1          "149.56.41.55:7778"
#define SERVER_IP2          "ca12.heavyhost.com.br:7778"
#define SERVER_FORUM        "vidarealcrias.forumeiros.com"
#define SERVER_FACEBOOK     "facebook.com/vidarealcrias"
#define SERVER_INSTAGRAM    "instagram.com/vidarealcrias"
#define SERVER_DISCORD      "discord.gg/8nyDuEv"

#include                        a_samp
#include                        a_mysql
#include                        streamer
#include                        pawn.cmd
#include                        sscanf2
#include                        crashdetect
#include                        ysf
#include                        discord-connector

main(){}

#include modules\defines
#include modules\variables
#include modules\discord

#define     MAILER_URL "spelsajten.net/mailer.php"
#include    mailer

/* TextDraws */
#include modules\textdraws\td_skinlist
#include modules\textdraws\td_barstatus
#include modules\textdraws\td_skinsstore
#include modules\textdraws\td_taximeter
#include modules\textdraws\td_detonated
#include modules\textdraws\td_alterpass
#include modules\textdraws\td_coding
#include modules\textdraws\td_antiafk
#include modules\textdraws\td_time
#include modules\textdraws\td_tutorial
#include modules\textdraws\td_vehiclestate
#include modules\textdraws\td_prision
#include modules\textdraws\td_concessionaire
#include modules\textdraws\td_identity
#include modules\textdraws\td_ban
#include modules\textdraws\td_loading
#include modules\textdraws\td_jetpack
#include modules\textdraws\td_base
#include modules\textdraws\td_gift
#include modules\textdraws\td_sleep
#include modules\textdraws\td_loginscreen

/* Database */
#include modules\database\db_accounts
#include modules\database\db_accessories
#include modules\database\db_itens
#include modules\database\db_identidade
#include modules\database\db_ban
#include modules\database\db_bag
#include modules\database\db_status
#include modules\database\db_vehicles
#include modules\database\db_business
#include modules\database\db_cnh
#include modules\database\db_staffs
#include modules\database\db_tags
#include modules\database\db_timers
#include modules\database\db_transfer
#include modules\database\db_server
#include modules\database\db_schedulingcnh
#include modules\database\db_weaponproducer
#include modules\database\db_gift
#include modules\database\db_sweet

/* Player */
#include modules\player\py_versioncheck
#include modules\player\py_mobile
#include modules\player\py_functions
#include modules\player\py_bag
#include modules\player\py_accessories
#include modules\player\py_skinsstore
#include modules\player\py_arena
#include modules\player\py_sleep
#include modules\player\py_barstatus
#include modules\player\py_loginscreen
#include modules\player\py_vips
#include modules\player\py_disease
#include modules\player\py_antiafk
#include modules\player\py_dbweaponblock
#include modules\player\py_disconnect
#include modules\player\py_locate
#include modules\player\py_identity
#include modules\player\py_jetpack
#include modules\player\py_gunsscallop
#include modules\player\py_drivingschool
#include modules\player\py_cnh
#include modules\player\py_gift
#include modules\player\py_sweet
#include modules\player\py_hud
#include modules\player\py_dm
#include modules\player\py_rentcar

/* Modules */
#include modules\safety
#include modules\serverconfig
#include modules\tax
#include modules\agency
#include modules\dialogs
#include modules\vehicles
#include modules\bases
#include modules\houses
#include modules\concessionaire
#include modules\bank
#include modules\hud
#include modules\speedometer
#include modules\enterexit
#include modules\hospital
#include modules\fuelstation
#include modules\realestate
#include modules\msgrandom
#include modules\npcs
#include modules\gps
#include modules\office
#include modules\prison
#include modules\removebug
#include modules\tutorial
#include modules\texts
#include modules\townhall
#include modules\merchandise

/* Objects */
#include modules\object\obj_cashmachine
#include modules\object\obj_objects
#include modules\object\obj_radars
#include modules\object\obj_labels
#include modules\object\obj_pickups
#include modules\object\obj_mapicons
#include modules\object\obj_tolls
#include modules\object\obj_checkpoints
#include modules\object\obj_hospital
#include modules\object\obj_remove

/* Profission */
#include modules\profession\honest\pfs_ej
#include modules\profession\honest\pfs_pizzaboy
#include modules\profession\honest\pfs_motoboy
#include modules\profession\honest\pfs_gari
#include modules\profession\honest\pfs_paramedic
#include modules\profession\honest\pfs_lawyer
#include modules\profession\honest\pfs_light
#include modules\profession\honest\pfs_mechanical

#include modules\profession\transport\pfs_taxi
#include modules\profession\transport\pfs_tanker
#include modules\profession\transport\pfs_taxiair
#include modules\profession\transport\pfs_strongcardriver
#include modules\profession\transport\pfs_loader
#include modules\profession\transport\pfs_minerals
#include modules\profession\transport\pfs_woods

#include modules\profession\police\pfs_police
#include modules\profession\police\pfs_strongcarsecurity

#include modules\profession\government\pfs_internalaffairs
#include modules\profession\government\pfs_navy
#include modules\profession\government\pfs_army
#include modules\profession\government\pfs_aeronautics

#include modules\profession\mob\pfs_potplanter
#include modules\profession\mob\pfs_thief
#include modules\profession\mob\pfs_weaponproducer

/* Player Commands*/
#include modules\player\command\cmds_general
#include modules\player\command\cmds_both

/* Events */
//----------------------------------------------------

/* Anti Cheats */
#include modules\anticheats\ac_config
