/*
 * GetPsiTableInfo.c
 *
 *  Created on: 2017年9月5日
 *      Author: Administrator
 */
#include <stdio.h>

#include "ParseTS_Length.h"

#include "TsParser.h"
#include "Parse_EIT.h"
#include "Parse_EMM.h"
#include "Parse_PAT.h"
#include "Parse_PMT.h"
#include "Parse_CAT.h"
#include "Parse_SDT.h"
#include "Parse_BAT.h"
#include "Parse_NIT.h"
#include "Parse_TDT.h"
#include "Parse_TOT.h"
#include "Parse_RST.h"
#include "Parse_ST.h"
#include "Parse_DIT.h"
#include "Parse_SIT.h"
#include "TestFuction.h"
#include "GetPsiTableInfo.h"

#define PROGRAM_MAX 128
#define CA_SYSTEM_MAX 64

#define EIT_PF_ACTUAL_TABLE_ID 0x4e
#define EIT_EIT_SCHEDULE_TABLE_ID_ONE 0x50
#define EIT_EIT_SCHEDULE_TABLE_ID_TWO 0x51

//获所有PMT表
int GetAllPmtTable(FILE *pfTsFile, TS_CAT_T *pstCAT)
{
	return 0;
}

//获取NIT
int GetNitTable(FILE *pfTsFile, TS_NIT_T *pstNIT,int *piTransportStreamCount)
{
	int iTsPosition = 0;
	int iTsLength = 0;
	iTsLength = ParseTsLength(pfTsFile, &iTsPosition);
	if (-1 == iTsLength)
	{
		DUBUGPRINTF("The file is not the transport stream file\n");
		return -1;
	}
	return ParseNIT_Table(pfTsFile, iTsPosition, iTsLength, pstNIT, piTransportStreamCount);
}

//获取CAT
int GetCatTable(FILE *pfTsFile, TS_CAT_T *pstCAT)
{
	int iTsPosition = 0;
	int iTsLength = 0;
	CAT_INFO_T stCAT_Info[CA_SYSTEM_MAX] = { 0 };
	iTsLength = ParseTsLength(pfTsFile, &iTsPosition);
	if (-1 == iTsLength)
	{
		DUBUGPRINTF("The file is not the transport stream file\n");
		return -1;
	}
	return ParseCAT_Table(pfTsFile, iTsPosition, iTsLength, stCAT_Info, pstCAT);
}

//获取PAT
int GetPatTable(FILE *pfTsFile, TS_PAT_T *pstPAT)
{
	int iTsPosition = 0;
	int iTsLength = 0;
	PAT_INFO_T stPAT_Info[PROGRAM_MAX] = { 0 };
	iTsLength = ParseTsLength(pfTsFile, &iTsPosition);
	if (-1 == iTsLength)
	{
		DUBUGPRINTF("The file is not the transport stream file\n");
		return -1;
	}
	return ParsePAT_Table(pfTsFile, iTsPosition, iTsLength, stPAT_Info, pstPAT);
}
