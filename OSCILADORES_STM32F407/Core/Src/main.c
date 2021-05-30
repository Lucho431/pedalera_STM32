/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dac.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "osc_dac_lfs.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define NOTA_C1 24
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//const unsigned long tabla_seno_vieja[] = {686,689,692,695,698,702,705,708,711,714,717,721,724,727,730,733,737,740,743,746,749,752,756,759,762,765,768,771,774,778,781,784,787,790,793,796,800,803,806,809,812,815,818,821,825,828,831,834,837,840,843,846,849,852,855,859,862,865,868,871,874,877,880,883,886,889,892,895,898,901,904,907,910,913,916,919,922,925,928,931,934,937,940,943,946,949,952,955,957,960,963,966,969,972,975,978,981,983,986,989,992,995,998,1000,1003,1006,1009,1012,1014,1017,1020,1023,1025,1028,1031,1034,1036,1039,1042,1045,1047,1050,1053,1055,1058,1061,1063,1066,1068,1071,1074,1076,1079,1081,1084,1087,1089,1092,1094,1097,1099,1102,1104,1107,1109,1112,1114,1117,1119,1122,1124,1126,1129,1131,1134,1136,1138,1141,1143,1145,1148,1150,1152,1155,1157,1159,1162,1164,1166,1168,1171,1173,1175,1177,1179,1182,1184,1186,1188,1190,1192,1194,1196,1199,1201,1203,1205,1207,1209,1211,1213,1215,1217,1219,1221,1223,1225,1227,1228,1230,1232,1234,1236,1238,1240,1242,1243,1245,1247,1249,1251,1252,1254,1256,1257,1259,1261,1263,1264,1266,1268,1269,1271,1272,1274,1276,1277,1279,1280,1282,1283,
//									1285,1286,1288,1289,1291,1292,1293,1295,1296,1298,1299,1300,1302,1303,1304,1306,1307,1308,1310,1311,1312,1313,1314,1316,1317,1318,1319,1320,1321,1323,1324,1325,1326,1327,1328,1329,1330,1331,1332,1333,1334,1335,1336,1337,1338,1338,1339,1340,1341,1342,1343,1343,1344,1345,1346,1346,1347,1348,1349,1349,1350,1351,1351,1352,1353,1353,1354,1354,1355,1355,1356,1356,1357,1357,1358,1358,1359,1359,1360,1360,1360,1361,1361,1361,1362,1362,1362,1363,1363,1363,1363,1364,1364,1364,1364,1364,1364,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1364,1364,1364,1364,1364,1364,1363,1363,1363,1363,1362,1362,1362,1361,1361,1361,1360,1360,1360,1359,1359,1358,1358,1357,1357,1357,1356,1355,1355,1354,1354,1353,1353,1352,1351,1351,1350,1349,1349,1348,1347,1347,1346,1345,1344,1344,1343,1342,1341,1340,1339,1339,1338,1337,1336,1335,1334,1333,1332,1331,1330,1329,1328,1327,1326,1325,1324,1323,1322,1321,1319,1318,1317,1316,1315,1314,1312,1311,1310,1309,1307,1306,1305,1303,1302,1301,1299,1298,1297,1295,1294,1292,1291,1290,1288,1287,1285,1284,1282,
//									1281,1279,1277,1276,1274,1273,1271,1270,1268,1266,1265,1263,1261,1260,1258,1256,1254,1253,1251,1249,1247,1246,1244,1242,1240,1238,1236,1235,1233,1231,1229,1227,1225,1223,1221,1219,1217,1215,1213,1211,1209,1207,1205,1203,1201,1199,1197,1195,1193,1191,1189,1186,1184,1182,1180,1178,1176,1173,1171,1169,1167,1164,1162,1160,1158,1155,1153,1151,1148,1146,1144,1141,1139,1137,1134,1132,1129,1127,1125,1122,1120,1117,1115,1112,1110,1107,1105,1102,1100,1097,1095,1092,1090,1087,1085,1082,1080,1077,1074,1072,1069,1066,1064,1061,1059,1056,1053,1051,1048,1045,1043,1040,1037,1034,1032,1029,1026,1023,1021,1018,1015,1012,1010,1007,1004,1001,998,995,993,990,987,984,981,978,976,973,970,967,964,961,958,955,952,949,947,944,941,938,935,932,929,926,923,920,917,914,911,908,905,902,899,896,893,890,887,884,881,878,875,872,869,865,862,859,856,853,850,847,844,841,838,835,832,828,825,822,819,816,813,810,807,803,800,797,794,791,788,785,782,778,775,772,769,766,763,759,756,753,750,747,744,740,737,734,731,728,725,721,718,715,712,709,706,702,699,696,693,690,686,683,680,677,674,671,667,
//									664,661,658,655,652,648,645,642,639,636,632,629,626,623,620,617,613,610,607,604,601,598,594,591,588,585,582,579,576,572,569,566,563,560,557,554,551,547,544,541,538,535,532,529,526,523,520,516,513,510,507,504,501,498,495,492,489,486,483,480,477,474,471,468,465,462,459,456,453,450,447,444,441,438,435,432,429,426,423,420,417,414,411,408,405,402,400,397,394,391,388,385,382,379,377,374,371,368,365,362,360,357,354,351,349,346,343,340,337,335,332,329,327,324,321,318,316,313,310,308,305,302,300,297,295,292,289,287,284,282,279,276,274,271,269,266,264,261,259,256,254,251,249,246,244,242,239,237,234,232,230,227,225,222,220,218,215,213,211,209,206,204,202,199,197,195,193,191,188,186,184,182,180,178,175,173,171,169,167,165,163,161,159,157,155,153,151,149,147,145,143,141,139,137,135,133,131,129,128,126,124,122,120,118,117,115,113,111,110,108,106,105,103,101,100,98,96,95,93,91,90,88,87,85,84,82,81,79,78,76,75,73,72,70,69,68,66,65,64,62,61,60,58,57,56,55,53,52,51,50,48,47,46,45,44,43,42,41,39,38,37,36,35,34,33,32,31,30,30,29,28,27,26,25,24,23,23,22,21,
//									20,19,19,18,17,17,16,15,15,14,13,13,12,11,11,10,10,9,9,8,8,7,7,6,6,6,5,5,4,4,4,3,3,3,2,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,5,5,6,6,6,7,7,8,8,9,9,10,10,11,12,12,13,13,14,15,15,16,17,17,18,19,20,20,21,22,23,24,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,48,49,50,51,52,54,55,56,57,59,60,61,63,64,65,67,68,69,71,72,74,75,77,78,80,81,83,84,86,87,89,90,92,93,95,97,98,100,102,103,105,107,108,110,112,114,115,117,119,121,123,124,126,128,130,132,134,136,137,139,141,143,145,147,149,151,153,155,157,159,161,163,165,168,170,172,174,176,178,180,182,185,187,189,191,193,196,198,200,202,205,207,209,211,214,216,218,221,223,225,228,230,233,235,237,240,242,245,247,250,252,254,257,259,262,264,267,269,272,275,277,280,282,285,287,290,293,295,298,300,303,306,308,311,314,316,319,322,325,327,330,333,335,338,341,344,346,349,352,355,358,360,363,366,369,372,374,377,380,383,386,389,392,394,397,400,403,406,409,412,415,418,421,424,427,430,432,435,438,441,444,447,450,453,456,459,462,465,468,471,474,477,480,484,
//									487,490,493,496,499,502,505,508,511,514,517,520,523,526,530,533,536,539,542,545,548,551,554,558,561,564,567,570,573,576,580,583,586,589,592,595,598,602,605,608,611,614,617,621,624,627,630,633,636,640,643,646,649,652,655,659,662,665,668,671,675,678,681,};
//
//const unsigned long tabla_cuadrada_vieja[] = {1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,
//										1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,
//										1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,
//										1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,1365,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//										0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
//
//const unsigned long tabla_sierra_vieja[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,
//										255,256,257,258,259,260,261,262,263,264,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,
//										483,484,485,486,487,488,489,490,491,492,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,570,571,572,573,574,575,576,577,
//										578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,643,644,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697,698,699,700,701,702,703,704,705,706,707,708,709,710,711,712,713,714,715,716,717,718,719,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736,737,738,739,740,741,742,743,744,745,746,747,748,749,750,751,752,753,754,755,756,757,758,759,760,761,762,763,764,765,766,767,768,769,770,771,772,773,774,775,776,777,778,779,780,781,782,783,784,785,786,787,788,789,790,791,792,793,794,795,797,798,799,800,801,802,803,804,805,
//										806,807,808,809,810,811,812,813,814,815,816,817,818,819,820,821,822,823,824,825,826,827,828,829,830,831,832,833,834,835,836,837,838,839,840,841,842,843,844,845,846,847,848,849,850,851,852,853,854,855,856,857,858,859,860,861,862,863,864,865,866,867,868,869,870,871,873,874,875,876,877,878,879,880,881,882,883,884,885,886,887,888,889,890,891,892,893,894,895,896,897,898,899,900,901,902,903,904,905,906,907,908,909,910,911,912,913,914,915,916,917,918,919,920,921,922,923,924,925,926,927,928,929,930,931,932,933,934,935,936,937,938,939,940,941,942,943,944,945,946,947,949,950,951,952,953,954,955,956,957,958,959,960,961,962,963,964,965,966,967,968,969,970,971,972,973,974,975,976,977,978,979,980,981,982,983,984,985,986,987,988,989,990,991,992,993,994,995,996,997,998,999,1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020,1021,1022,1023,1025,1026,1027,
//										1028,1029,1030,1031,1032,1033,1034,1035,1036,1037,1038,1039,1040,1041,1042,1043,1044,1045,1046,1047,1048,1049,1050,1051,1052,1053,1054,1055,1056,1057,1058,1059,1060,1061,1062,1063,1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1086,1087,1088,1089,1090,1091,1092,1093,1094,1095,1096,1097,1098,1099,1101,1102,1103,1104,1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118,1119,1120,1121,1122,1123,1124,1125,1126,1127,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1138,1139,1140,1141,1142,1143,1144,1145,1146,1147,1148,1149,1150,1151,1152,1153,1154,1155,1156,1157,1158,1159,1160,1161,1162,1163,1164,1165,1166,1167,1168,1169,1170,1171,1172,1173,1174,1176,1177,1178,1179,1180,1181,1182,1183,1184,1185,1186,1187,1188,1189,1190,1191,1192,1193,1194,1195,1196,1197,1198,1199,1200,1201,1202,1203,1204,1205,1206,1207,1208,1209,1210,
//										1211,1212,1213,1214,1215,1216,1217,1218,1219,1220,1221,1222,1223,1224,1225,1226,1227,1228,1229,1230,1231,1232,1233,1234,1235,1236,1237,1238,1239,1240,1241,1242,1243,1244,1245,1246,1247,1248,1249,1250,1252,1253,1254,1255,1256,1257,1258,1259,1260,1261,1262,1263,1264,1265,1266,1267,1268,1269,1270,1271,1272,1273,1274,1275,1276,1277,1278,1279,1280,1281,1282,1283,1284,1285,1286,1287,1288,1289,1290,1291,1292,1293,1294,1295,1296,1297,1298,1299,1300,1301,1302,1303,1304,1305,1306,1307,1308,1309,1310,1311,1312,1313,1314,1315,1316,1317,1318,1319,1320,1321,1322,1323,1324,1325,1326,1328,1329,1330,1331,1332,1333,1334,1335,1336,1337,1338,1339,1340,1341,1342,1343,1344,1345,1346,1347,1348,1349,1350,1351,1352,1353,1354,1355,1356,1357,1358,1359,1360,1361,1362,1363,1364,1365,};

//uint16_t phase = 0;
uint8_t flag_dac = 0;

uint8_t read_tecla[3] = {0, 0, 0};
uint8_t last_tecla[3] = {0, 0, 0};

uint8_t testNota[3] = {NOTA_C1, 36, 60};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DAC_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  //HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
  osc_dac_init(&hdac, DAC_CHANNEL_1);
  osc_setRatios(100, 100, 100);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  read_tecla[0] = HAL_GPIO_ReadPin(DO_GPIO_Port, DO_Pin);
	  read_tecla[1] = HAL_GPIO_ReadPin(REb_GPIO_Port, REb_Pin);
	  read_tecla[2] = HAL_GPIO_ReadPin(RE_GPIO_Port, RE_Pin);

	  for (uint8_t i = 0; i < 3; i++){
		  if (!read_tecla[i] && last_tecla[i]){
			  osc_setNote(NOTA_C1 + i);
//			  osc_setNote(testNota[i]);
		  }else if(read_tecla[i] && !last_tecla[i]){
			  osc_setNote(0);
		  }
		  last_tecla[i]= read_tecla[i];
	  }//end for

	  if (flag_dac != 0){
		  osc_dac_update();
		  flag_dac = 0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2){
		flag_dac = 1;
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
