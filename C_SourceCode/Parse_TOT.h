#ifndef _PARSE_TOT_H_
#define _PARSE_TOT_H_

#define TOT_DESCRIPTOR_MAX 4096

typedef struct TS_TOT_T
{
	unsigned int uiTable_id :8;
	unsigned int uiSection_syntax_indicator :1;
	unsigned int uiReserved_future_use :1;
	unsigned int uiReserved_first :2;
	unsigned int uiSection_length :12;
	unsigned int auiUTC_time[5];
	unsigned int uiReserved_second :4;
	unsigned int uiDescriptors_loop_length :12;
	unsigned char aucDescriptor[TOT_DESCRIPTOR_MAX];
	unsigned long uiCRC_32 :32;
} TS_TOT_T;

int ParseTOT_Table(FILE *pfTsFile, int iTsPosition, int iTsLength, TS_TOT_T *pstTS_TOT);
#endif
