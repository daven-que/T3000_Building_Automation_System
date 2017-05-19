// NewTstatSchedulesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "T3000.h"
#include "NewTstatSchedulesDlg.h"
#include "afxdialogex.h"
#include "global_function.h"
#include <bitset>
#include "SetTimeDlg.h"

// CNewTstatSchedulesDlg dialog

IMPLEMENT_DYNAMIC(CNewTstatSchedulesDlg, CDialogEx)

CNewTstatSchedulesDlg::CNewTstatSchedulesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewTstatSchedulesDlg::IDD, pParent)
{
	 
		m_curRow = 0;
		m_curCol = 0;
		memset(m_SchduleBuffer, 0xFF, 100);
}

CNewTstatSchedulesDlg::~CNewTstatSchedulesDlg()
{

}

void CNewTstatSchedulesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, WeeeklyList);

	DDX_Control(pDX, IDC_DATETIMEPICKER1_SCHEDUAL, m_schedual_time_picker);
}


BEGIN_MESSAGE_MAP(CNewTstatSchedulesDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CNewTstatSchedulesDlg::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CNewTstatSchedulesDlg::OnBnClickedButtonDelete)
	ON_MESSAGE(WM_LIST_ITEM_CHANGED,Fresh_Input_Item)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CNewTstatSchedulesDlg::OnNMClickList1)
	ON_NOTIFY(NM_KILLFOCUS, IDC_DATETIMEPICKER1_SCHEDUAL, &CNewTstatSchedulesDlg::OnNMKillfocusDatetimepicker1Schedual)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE_COPY_BTN, &CNewTstatSchedulesDlg::OnBnClickedButtonScheduleCopyBtn)
	ON_BN_CLICKED(IDOK, &CNewTstatSchedulesDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_ENABLE_SCHEDULE, &CNewTstatSchedulesDlg::OnBnClickedCheckEnableSchedule)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CNewTstatSchedulesDlg::OnNMDblclkList1)
END_MESSAGE_MAP()


// CNewTstatSchedulesDlg message handlers


int CNewTstatSchedulesDlg::GetEventNumber(int DayIndex)
{
	int RegNumber = DayIndex / 6;
	int Position = DayIndex % 6;
	std::bitset<16> RegBits(m_SchduleBuffer[96+RegNumber]);
	
	int eventNumber = 2 * RegBits[2*Position + 1] + RegBits[2*Position];

	return eventNumber;
}
void CNewTstatSchedulesDlg::LoadSheduleDataAndColor()
{
		
	Read_Multi(g_tstat_id, m_SchduleBuffer, 813, 104, 5);
	
	for (int i=0;i<48;i++)
	{
		Schedule_Node SN;
		WeeklyEvent[i].Day = i / 6;
		if (m_SchduleBuffer[2 * i]>23|| m_SchduleBuffer[2 * i + 1]>59)
		{
			continue;
		}
		if (m_SchduleBuffer[2*i] == 0 && m_SchduleBuffer[2 * i + 1]==0)
		{
			continue;
		}
		WeeklyEvent[i].Hour = m_SchduleBuffer[2 * i];
		WeeklyEvent[i].Minite = m_SchduleBuffer[2 * i + 1];
		WeeklyEvent[i].Event_Number = GetEventNumber(i);
		SN.Hour = m_SchduleBuffer[2 * i];
		SN.Minite = m_SchduleBuffer[2 * i + 1];
		if (WeeklyEvent[i].Day == 0)
		{
			SN.Monday = WeeklyEvent[i].Event_Number;
		} 
		else if (WeeklyEvent[i].Day == 1)
		{
			SN.Tuesday = WeeklyEvent[i].Event_Number;
		}
		else if (WeeklyEvent[i].Day == 2)
		{
			SN.Wednesday = WeeklyEvent[i].Event_Number;
		}
		else if (WeeklyEvent[i].Day == 3)
		{
			SN.Thursday = WeeklyEvent[i].Event_Number;
		}
		else if (WeeklyEvent[i].Day == 4)
		{
			SN.Friday = WeeklyEvent[i].Event_Number;
		}
		else if (WeeklyEvent[i].Day == 5)
		{
			SN.Saturday = WeeklyEvent[i].Event_Number;
		}
		else if (WeeklyEvent[i].Day == 6)
		{
			SN.Sunday = WeeklyEvent[i].Event_Number;
		}
		else if (WeeklyEvent[i].Day == 7)
		{
			SN.Holiday = WeeklyEvent[i].Event_Number;
		}
		InsertAndUpdate_Schdule(SN);
	}
	m_ScheduleList.sort();
	list<Schedule_Node>::iterator it;
	int index = 0;
	for (it = m_ScheduleList.begin(); it != m_ScheduleList.end(); ++it)
	{
		it->Col_Monday = m_COLScheduleMode[it->Monday];
		if (it->Monday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 2);
			 
			it->Col_Monday = PreviousScheduleColor;
		}

		 

		it->Col_Tuesday = m_COLScheduleMode[it->Tuesday];
		if (it->Tuesday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 3);
			 
			it->Col_Tuesday = PreviousScheduleColor;
		}

		 

		it->Col_Wednesday = m_COLScheduleMode[it->Wednesday];
		if (it->Wednesday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 4);
		 
			it->Col_Wednesday = PreviousScheduleColor;
		}

		 

		it->Col_Thursday = m_COLScheduleMode[it->Thursday];
		if (it->Thursday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 5);
			 
			it->Col_Thursday = PreviousScheduleColor;
		}

	 
		it->Col_Friday = m_COLScheduleMode[it->Friday];
		if (it->Friday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 6);
			 
			it->Col_Friday = PreviousScheduleColor;
		}

	 

		it->Col_Saturday = m_COLScheduleMode[it->Saturday];
		if (it->Saturday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 7);
			 
			it->Col_Saturday = PreviousScheduleColor;
		}

	 
		it->Col_Sunday = m_COLScheduleMode[it->Sunday];
		if (it->Sunday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 8);
			 
			it->Col_Sunday = PreviousScheduleColor;
		}
 
		it->Col_Holiday = m_COLScheduleMode[it->Holiday];
		if (it->Holiday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 9);
		 
			it->Col_Holiday = PreviousScheduleColor;
		}


		index++;
	}


}

BOOL CNewTstatSchedulesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_strScheduleMode[0]=L"";
	m_strScheduleMode[1]=L"Home";
	m_strScheduleMode[2]=L"Work";
	m_strScheduleMode[3]=L"Sleep";
	
	m_COLScheduleMode[0] = RGB(238, 44, 44);
	m_COLScheduleMode[1] = RGB(153, 50, 204);
	m_COLScheduleMode[2] = RGB(143, 188, 143);
	m_COLScheduleMode[3] = RGB(238, 44, 44);

	LoadSheduleDataAndColor();
	WeeeklyList.ModifyStyle(0, LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	//m_input_list.SetExtendedStyle(m_input_list.GetExtendedStyle() |LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES);
	WeeeklyList.SetExtendedStyle(WeeeklyList.GetExtendedStyle() |LVS_EX_GRIDLINES&(~LVS_EX_FULLROWSELECT));//Not allow full row select.
	WeeeklyList.InsertColumn(0, _T("Item"), 40, ListCtrlEx::Normal, LVCFMT_LEFT, ListCtrlEx::SortByDigit);
	WeeeklyList.InsertColumn(1, _T("Time"), 80, ListCtrlEx::EditBox, LVCFMT_LEFT, ListCtrlEx::SortByDigit);
	WeeeklyList.InsertColumn(2, _T("Monday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByDigit);
	WeeeklyList.InsertColumn(3, _T("Tuesday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.InsertColumn(4, _T("Wednesday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.InsertColumn(5, _T("Thursday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.InsertColumn(6, _T("Friday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.InsertColumn(7, _T("Saturday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.InsertColumn(8, _T("Sunday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.InsertColumn(9, _T("Holiday"), 80, ListCtrlEx::ComboBox, LVCFMT_LEFT, ListCtrlEx::SortByString);
	WeeeklyList.SetBkColor(RGB(205,201,201)) ;
	
	 
	g_hwnd_now = this->m_hWnd;
	
	ListCtrlEx::CStrList strlist;
	strlist.clear();
	strlist.push_back(L"");
	strlist.push_back(L"Home");
	strlist.push_back(L"Work");
	strlist.push_back(L"Sleep");
	list<Schedule_Node>::iterator it;
	int index=0;
	for (it = m_ScheduleList.begin();it!=m_ScheduleList.end();++it)
	{
		 
		 
		CString strTime;
		int Item=index+1;
		strTime.Format(_T("%d"),Item);
		WeeeklyList.InsertItem(index,strTime);
		strTime.Format(_T("%02d:%02d"),it->Hour,it->Minite);
		WeeeklyList.SetItemBkColor(index,0,RGB(255,255,255),0);
		WeeeklyList.SetItemText(index,1,strTime);
		WeeeklyList.SetItemBkColor(index,1,RGB(255,255,255),0);
		WeeeklyList.SetWhetherShowBkCol(false);
		//设置Combox
		for (int col = 2;col<10;col++)
		{
			WeeeklyList.SetCellStringList(index, col, strlist);
		}
		WeeeklyList.SetItemText(index,2,m_strScheduleMode[it->Monday]);
		WeeeklyList.SetItemBkColor(index,2,it->Col_Monday,0);
		WeeeklyList.SetItemText(index,3,m_strScheduleMode[it->Tuesday]);
		WeeeklyList.SetItemBkColor(index,3,it->Col_Tuesday,0);
		WeeeklyList.SetItemText(index,4,m_strScheduleMode[it->Wednesday]);
		WeeeklyList.SetItemBkColor(index,4,it->Col_Wednesday,0);
		WeeeklyList.SetItemText(index,5,m_strScheduleMode[it->Thursday]);
		WeeeklyList.SetItemBkColor(index,5,it->Col_Thursday,0);
		WeeeklyList.SetItemText(index,6,m_strScheduleMode[it->Friday]);
		WeeeklyList.SetItemBkColor(index,6,it->Col_Friday,0);
		WeeeklyList.SetItemText(index,7,m_strScheduleMode[it->Saturday]);
		WeeeklyList.SetItemBkColor(index,7,it->Col_Saturday,0);
		WeeeklyList.SetItemText(index,8,m_strScheduleMode[it->Sunday]);
		WeeeklyList.SetItemBkColor(index,8,it->Col_Sunday,0);
		WeeeklyList.SetItemText(index, 9, m_strScheduleMode[it->Holiday]);
		WeeeklyList.SetItemBkColor(index, 9, it->Col_Holiday, 0);

		index++;
	 
	}
	
	if (product_register_value[MODBUS_SCHEDULE_ON_OFF] == 1)
	{
		 
			((CButton *)GetDlgItem(IDC_CHECK_ENABLE_SCHEDULE))->SetCheck(1);
	}
	else
	{

		   ((CButton *)GetDlgItem(IDC_CHECK_ENABLE_SCHEDULE))->SetCheck(0);
	}
	
	WeeeklyList.GetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
void CNewTstatSchedulesDlg::Fresh_List()
{
	ListCtrlEx::CStrList strlist;
	strlist.clear();
	strlist.push_back(L"");
	strlist.push_back(L"Home");
	strlist.push_back(L"Work");
	strlist.push_back(L"Sleep");
	 
	list<Schedule_Node>::iterator it;
	int index=0;
	for (it = m_ScheduleList.begin();it!=m_ScheduleList.end();++it)
	{


		CString strTime;
		int Item=index+1;
		strTime.Format(_T("%d"),Item);
		WeeeklyList.SetItemText(index,0,strTime);
		WeeeklyList.SetItemBkColor(index,0,RGB(255,255,255),0);
		strTime.Format(_T("%02d:%02d"),it->Hour,it->Minite);
		/*WeeeklyList.InsertItem(index++,L"");*/
		WeeeklyList.SetItemText(index,1,strTime);
		WeeeklyList.SetItemBkColor(index,1,RGB(255,255,255),0);
		WeeeklyList.SetWhetherShowBkCol(false);
		//设置Combox
		for (int col = 2;col<10;col++)
		{
			WeeeklyList.SetCellStringList(index, col, strlist);

		}
		WeeeklyList.SetItemText(index,2,m_strScheduleMode[it->Monday]);
		WeeeklyList.SetItemBkColor(index,2,m_COLScheduleMode[it->Monday],0);
		it->Col_Monday = m_COLScheduleMode[it->Monday];
		if (it->Monday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,2); 
			WeeeklyList.SetItemBkColor(index,2,PreviousScheduleColor,0);
			it->Col_Monday = PreviousScheduleColor;
		}
		  
		WeeeklyList.SetItemText(index,3,m_strScheduleMode[it->Tuesday]);
		WeeeklyList.SetItemBkColor(index,3,m_COLScheduleMode[it->Tuesday],0);
		
		it->Col_Tuesday = m_COLScheduleMode[it->Tuesday];
		if (it->Tuesday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,3); 
			WeeeklyList.SetItemBkColor(index,3,PreviousScheduleColor,0);
			it->Col_Tuesday = PreviousScheduleColor;
		}

		WeeeklyList.SetItemText(index,4,m_strScheduleMode[it->Wednesday]);
		WeeeklyList.SetItemBkColor(index,4,m_COLScheduleMode[it->Wednesday],0);

		it->Col_Wednesday = m_COLScheduleMode[it->Wednesday];
		if (it->Wednesday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,4); 
			WeeeklyList.SetItemBkColor(index,4,PreviousScheduleColor,0);
			it->Col_Wednesday = PreviousScheduleColor;
		}

		WeeeklyList.SetItemText(index,5,m_strScheduleMode[it->Thursday]);
		WeeeklyList.SetItemBkColor(index,5,m_COLScheduleMode[it->Thursday],0);

		it->Col_Thursday = m_COLScheduleMode[it->Thursday];
		if (it->Thursday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,5); 
			WeeeklyList.SetItemBkColor(index,5,PreviousScheduleColor,0);
			it->Col_Thursday = PreviousScheduleColor;
		}

		WeeeklyList.SetItemText(index,6,m_strScheduleMode[it->Friday]);
		WeeeklyList.SetItemBkColor(index,6,m_COLScheduleMode[it->Friday],0);

		it->Col_Friday = m_COLScheduleMode[it->Friday];
		if (it->Friday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,6); 
			WeeeklyList.SetItemBkColor(index,6,PreviousScheduleColor,0);
			it->Col_Friday = PreviousScheduleColor;
		}

		WeeeklyList.SetItemText(index,7,m_strScheduleMode[it->Saturday]);
		WeeeklyList.SetItemBkColor(index,7,m_COLScheduleMode[it->Saturday],0);

		it->Col_Saturday = m_COLScheduleMode[it->Saturday];
		if (it->Saturday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,7); 
			WeeeklyList.SetItemBkColor(index,7,PreviousScheduleColor,0);
			it->Col_Saturday = PreviousScheduleColor;
		}

		WeeeklyList.SetItemText(index,8,m_strScheduleMode[it->Sunday]);
		WeeeklyList.SetItemBkColor(index,8,m_COLScheduleMode[it->Sunday],0);
		it->Col_Sunday = m_COLScheduleMode[it->Sunday];
		if (it->Sunday == 0&&index!=0)
		{
			COLORREF PreviousScheduleColor=GetItemColor(index-1,8); 
			WeeeklyList.SetItemBkColor(index,8,PreviousScheduleColor,0);
			it->Col_Sunday = PreviousScheduleColor;
		}

		WeeeklyList.SetItemText(index, 9, m_strScheduleMode[it->Holiday]);
		WeeeklyList.SetItemBkColor(index, 9, m_COLScheduleMode[it->Holiday], 0);
		it->Col_Holiday = m_COLScheduleMode[it->Holiday];
		if (it->Holiday == 0 && index != 0)
		{
			COLORREF PreviousScheduleColor = GetItemColor(index - 1, 9);
			WeeeklyList.SetItemBkColor(index, 9, PreviousScheduleColor, 0);
			it->Col_Holiday = PreviousScheduleColor;
		}


		index++;
	}
}

int CNewTstatSchedulesDlg::getvalue(CString modelname)
{
	if (modelname.CompareNoCase(m_strScheduleMode[0])==0)
	{
		return 0;
	}
	else if (modelname.CompareNoCase(m_strScheduleMode[1])==0)
	{
		return 1;
	}
	else if (modelname.CompareNoCase(m_strScheduleMode[2])==0)
	{
		return 2;
	}
	else if (modelname.CompareNoCase(m_strScheduleMode[3])==0)
	{
		return 3;
	}
	 
	return -1;
	 
}

int CNewTstatSchedulesDlg::GetValueItem(int Row,int Col)
{
	list<Schedule_Node>::iterator it = GetNode(Row);
	int ReturnValue = -1;
	switch (Col)
	{
	case 1:
	     ReturnValue = it->Hour*60+it->Minite;
		 break;
	case 2:
		ReturnValue = it->Monday;
		break;
	case 3:
		ReturnValue = it->Tuesday;
		break;
	case 4:
		ReturnValue = it->Wednesday;
		break;
	case 5:
		ReturnValue = it->Thursday;
		break;
	case 6:
		ReturnValue = it->Friday;
		break;
	case 7:
		ReturnValue = it->Saturday;
		break;
	case 8:
		ReturnValue = it->Sunday;
		break;
	case 9:
		ReturnValue = it->Holiday;
		break;
	default:
		ReturnValue = -1;
	}
	return ReturnValue;
}
COLORREF CNewTstatSchedulesDlg::GetItemColor(int Row,int Col)
{
	list<Schedule_Node>::iterator it = GetNode(Row);
	COLORREF ReturnValue = -1;
	switch (Col)
	{
	case 2:
		ReturnValue = it->Col_Monday;
		break;
	case 3:
		ReturnValue = it->Col_Tuesday;
		break;
	case 4:
		ReturnValue = it->Col_Wednesday;
		break;
	case 5:
		ReturnValue = it->Col_Thursday;
		break;
	case 6:
		ReturnValue = it->Col_Friday;
		break;
	case 7:
		ReturnValue = it->Col_Saturday;
		break;
	case 8:
		ReturnValue = it->Col_Sunday;
		break;
	case 9:
		ReturnValue = it->Col_Holiday;
		break;
	default:
		ReturnValue = -1;
	}
	return ReturnValue;
	
}
void CNewTstatSchedulesDlg::SetValueItem(int Row,int Col,int Val)
{
	int position=0;
	 
	for (list<Schedule_Node>::iterator index = m_ScheduleList.begin();index !=m_ScheduleList.end() ;++index)
	{
		if (position == Row)
		{

			switch (Col)
			{
			case 1:
				   index->Hour = Val/60;
				   index->Minite = Val - index->Hour*60;
				   break;
			case 2:
				   index->Monday = Val;
				break;		 
			case 3:			 
				   index->Tuesday = Val ;
				break;		 
			case 4:			 
				   index->Wednesday = Val;
				break;		 
			case 5:			 
				   index->Thursday = Val;
				break;		 
			case 6:			 
				   index->Friday = Val;
				break;		 
			case 7:			 
				   index->Saturday = Val;
				break;		 
			case 8:			 
				index->Sunday = Val;
				break;		 
			case 9:
				index->Holiday = Val;
				break;
			
			}
			break;
		}
		position++;

	} 
}
int CNewTstatSchedulesDlg::GetDayScheduleCount(int Col)
{
	int ScheduleCount = 0;
	for (list<Schedule_Node>::iterator index = m_ScheduleList.begin();index !=m_ScheduleList.end() ;++index)
	{
		 
		 if (Col == 2 && index->Monday!=0)
		 {	
			 ScheduleCount++; 
		 } 
		 else  if (Col == 3 && index->Tuesday!=0)
		 {
			ScheduleCount++; 
		 }
		 else  if (Col == 4 && index->Wednesday!=0)
		 {
		  ScheduleCount++; 
		 }
		 else  if (Col == 5 && index->Thursday!=0)
		 {
		  ScheduleCount++; 
		 }
		 else  if (Col == 6 && index->Friday!=0)
		 {
		  ScheduleCount++; 
		 }
		 else  if (Col == 7 && index->Saturday!=0)
		 {
		  ScheduleCount++; 
		 }
		 else  if (Col == 8 && index->Sunday!=0)
		 {
		  ScheduleCount++; 
		 }
		 else  if (Col == 9 && index->Holiday != 0)
		 {
			 ScheduleCount++;
		 }
	} 

	return ScheduleCount;
}
LRESULT CNewTstatSchedulesDlg::Fresh_Input_Item(WPARAM wParam,LPARAM lParam)
{ 
	int Changed_Item = (int)wParam;
	int Changed_SubItem = (int)lParam;
	CString New_CString =  WeeeklyList.GetItemText(Changed_Item,Changed_SubItem);
	BOOL is_change = FALSE;
	if (Changed_SubItem>1)
	{
		int tempvalue = getvalue(New_CString); 
		if (tempvalue==0||(GetDayScheduleCount(Changed_SubItem)<=6))
		{
			if (GetValueItem(Changed_Item,Changed_SubItem)!=tempvalue)
			{
				SetValueItem(Changed_Item,Changed_SubItem,tempvalue);
				is_change = TRUE;
			}
		}
		else
		{
			AfxMessageBox(L"Can't be more than 6 !");
			is_change = TRUE;
		}

		
	}
	if (Changed_SubItem == 1)
	{
		CStringArray temparray;
		SplitCStringA(temparray,New_CString,_T(":"));
		if (temparray.GetSize()<=1)
		{
			AfxMessageBox(_T("The time that you input is not correct!"));
		   is_change = TRUE;
		}
		int Hour = _wtoi(temparray[0]);
		int minute = _wtoi(temparray[1]);
		int tempvalue = Hour*60+minute;
		
		if (GetValueItem(Changed_Item,Changed_SubItem)!=tempvalue)
		{
			SetValueItem(Changed_Item,Changed_SubItem,tempvalue);
			is_change = TRUE;
		}
		 
	}
	 
	Fresh_List();
	 

	return 0;
}

BOOL CNewTstatSchedulesDlg::Insert_Schdule(Schedule_Node SR,int POS)
{
	 int insert_time =SR.Hour*60+SR.Minite;
	BOOL is_exsit = FALSE;
 
	for (list<Schedule_Node>::iterator index = m_ScheduleList.begin();index !=m_ScheduleList.end() ;++index)
	{
		int ST=index->Hour*60+index->Minite;

		if (ST == insert_time)
		{
			is_exsit = TRUE;
		}
	}
	
	int position=0;
	if (!is_exsit)
	{
		for (list<Schedule_Node>::iterator index = m_ScheduleList.begin();index !=m_ScheduleList.end() ;++index)
		{
			if (position == POS)//找到了要插入的位置
			{
			    m_ScheduleList.insert(index,SR);
				/*return TRUE;*/
			}
			position++;
		} 
		
	}
	if (position!=POS)//没有找到要插入的位置，就直接添加到列表里面
	{
		m_ScheduleList.push_back(SR);
	}


	m_ScheduleList.sort();
	return TRUE;
}

BOOL CNewTstatSchedulesDlg::InsertAndUpdate_Schdule(Schedule_Node SR)
{
 	if (m_ScheduleList.size()<=0)
 	{
 		m_ScheduleList.push_back(SR);
 	}
 	else
 	{
 		int insert_time = SR.Hour * 60 + SR.Minite;
 		BOOL is_exsit = FALSE;
 		int POS = -1;
 		for (list<Schedule_Node>::iterator index = m_ScheduleList.begin(); index != m_ScheduleList.end(); ++index)
 		{
 			int ST = index->Hour * 60 + index->Minite;
 
 			if (ST == insert_time)
 			{
 				 is_exsit = TRUE;
                if (SR.Monday!=0)
                {
					index->Monday = SR.Monday;
                }
				if (SR.Tuesday != 0)
				{
					index->Tuesday = SR.Tuesday;
				}
				if (SR.Wednesday != 0)
				{
					index->Wednesday = SR.Wednesday;
				}
				if (SR.Thursday != 0)
				{
					index->Thursday = SR.Thursday;
				}
				if (SR.Friday != 0)
				{
					index->Friday = SR.Friday;
				}
				if (SR.Saturday != 0)
				{
					index->Saturday = SR.Saturday;
				}
				if (SR.Sunday != 0)
				{
					index->Sunday = SR.Sunday;
				}
				if (SR.Holiday != 0)
				{
					index->Holiday = SR.Holiday;
				}

                  
 			}
 			 
 
 		}
        if (!is_exsit)
        {
			m_ScheduleList.push_back(SR);
        }
 	 
 	}
	
	m_ScheduleList.sort();
	return FALSE;
}
BOOL CNewTstatSchedulesDlg::Delete_Schdule(int POS)
{
        int position=0;
	 
		for (list<Schedule_Node>::iterator index = m_ScheduleList.begin();index !=m_ScheduleList.end() ;++index)
		{
			if (position == POS)
			{
			   // m_ScheduleList.insert(index,SR);
				m_ScheduleList.erase(index);
				return TRUE;
			}
			position++;
		} 
	 
	return FALSE;
}
list<Schedule_Node>::iterator CNewTstatSchedulesDlg::GetNode(int POS){
	int position=0;
	list<Schedule_Node>::iterator returnnode = m_ScheduleList.begin();
	for (list<Schedule_Node>::iterator index = m_ScheduleList.begin();index !=m_ScheduleList.end() ;index++)
	{
		if (position == POS)
		{
			 
			returnnode= index;
		}
		position++;

	} 
	return returnnode;
}  
void CNewTstatSchedulesDlg::OnBnClickedButtonInsert()
{

 


 
		CSetTimeDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			CString temp = dlg.m_strTime;
			Schedule_Node sr;
			CStringArray aaa;
			SplitCStringA(aaa, temp, L":");
			if (aaa.GetSize() >= 2)
			{
				sr.Hour = _wtoi(aaa[0]);
				sr.Minite = _wtoi(aaa[1]);
				InsertAndUpdate_Schdule(sr);

				WeeeklyList.InsertItem(WeeeklyList.GetRowCount(), L"");
			}

			Fresh_List();

		}

 



}


void CNewTstatSchedulesDlg::OnBnClickedButtonDelete()
{
	if (WeeeklyList.GetRowCount()>0)
	{
		WeeeklyList.DeleteItem(m_curRow);
		Delete_Schdule(m_curRow);
	}
}

void CNewTstatSchedulesDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CString temp_cstring;
	long lRow,lCol;
	 
	DWORD dwPos=GetMessagePos();//Get which line is click by user.Set the check box, when user enter Insert it will jump to program dialog
	CPoint point( LOWORD(dwPos), HIWORD(dwPos));
	WeeeklyList.ScreenToClient(&point);
	LVHITTESTINFO lvinfo;
	lvinfo.pt=point;
	lvinfo.flags=LVHT_ABOVE;
	int nItem=WeeeklyList.SubItemHitTest(&lvinfo);

	lRow = lvinfo.iItem;
	lCol = lvinfo.iSubItem;


	if(lRow>WeeeklyList.GetItemCount()) //如果点击区超过最大行号，则点击是无效的
		return;
	if(lRow<0)
		return;

	m_curRow = lRow;
	m_curCol = lCol;
	if (m_curCol == 0)
	{
		Fresh_List();
		WeeeklyList.SetItemBkColor(lRow,-1,LIST_ITEM_SELECTED);
	}

	else if (m_curCol>1)
	{
		CString New_CString =  WeeeklyList.GetItemText(lRow,lCol);
		if(GetDayScheduleCount(lCol)>=6&&New_CString.IsEmpty())
		{
			WeeeklyList.Set_Edit(false);
			/*AfxMessageBox(L"Can't be more than 6 !");
			is_change = TRUE;*/
			MessageBox(_T("Can't be more than 6 tasks!"),_T("Warning"),MB_OK | MB_ICONINFORMATION);
		}
		else
		{
			WeeeklyList.Set_Edit(true);
		}
	} 
	else if (m_curCol == 1)
	{
		/*int Time = GetValueItem(lRow, lCol);
		m_hour = Time / 60;
		m_minute = Time - m_hour * 60;
		WeeeklyList.SetItemText(lRow, lCol, L"");
		m_schedual_time_picker.ShowWindow(SW_SHOW);
		CRect list_rect, win_rect;
		WeeeklyList.GetWindowRect(list_rect);
		GetWindowRect(win_rect);
		CRect myrect;
		WeeeklyList.GetSubItemRect(lRow, lCol, LVIR_BOUNDS, myrect);
		myrect.left = myrect.left + list_rect.left - win_rect.left;
		myrect.right = myrect.right + list_rect.left - win_rect.left;
		myrect.top = myrect.top + 11;
		myrect.bottom = myrect.bottom + 13;

		m_schedual_time_picker.BringWindowToTop();
		m_schedual_time_picker.MoveWindow(myrect);

		CTime TimeTemp(2016, 1, 1, m_hour, m_minute, 0);

		m_schedual_time_picker.SetFormat(_T("HH:mm"));
		m_schedual_time_picker.SetTime(&TimeTemp);
		m_schedual_time_picker.SetFocus();*/
	}
	else
	{
		
	}

	*pResult = 0;
}


void CNewTstatSchedulesDlg::OnNMKillfocusDatetimepicker1Schedual(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	CTime temp_time;CString temp_cs;
	int chour,cmin;
	m_schedual_time_picker.GetTime(temp_time);
	chour = temp_time.GetHour();
	cmin = temp_time.GetMinute();

	*pResult = 0;
}


BOOL CNewTstatSchedulesDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		if (GetFocus()->GetDlgCtrlID() ==IDC_LIST1 )
		{
			if (pMsg->wParam == VK_DELETE)
			{
				OnBnClickedButtonDelete();
				return TRUE;
			}
			else if (pMsg->wParam == VK_INSERT)
			{
				OnBnClickedButtonInsert();
				return TRUE;
			}
// 			else if (pMsg->wParam == VK_RETURN)
// 			{
// 				 
// 				CRect list_rect, win_rect;
// 				WeeeklyList.GetWindowRect(list_rect);
// 				ScreenToClient(&list_rect);
// 				::GetWindowRect(this->m_hWnd, win_rect);
// 				WeeeklyList.Set_My_WindowRect(win_rect);
// 				WeeeklyList.Set_My_ListRect(list_rect);
// 				WeeeklyList.Get_clicked_mouse_position();
// 				 
// 				return TRUE;
// 			}
		}
		

	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CNewTstatSchedulesDlg::CopyFromMonToFri()
{
	 
	for (list<Schedule_Node>::iterator index = m_ScheduleList.begin(); index != m_ScheduleList.end(); ++index)
	{
		 
		index->Tuesday = index->Wednesday = index->Thursday = index->Friday = index->Monday;

	}
}
void CNewTstatSchedulesDlg::OnBnClickedButtonScheduleCopyBtn()
{
 

	CopyFromMonToFri();
	 Fresh_List();
}

int CNewTstatSchedulesDlg::PowerFour(int number, int index)
{
	int retvalue = 1;
	for (int i = 1;i<=index;i++)
	{
		retvalue = retvalue * number;
	}
	return retvalue;
}
void CNewTstatSchedulesDlg::OnBnClickedOk()
{
	 
	for (list<Schedule_Node>::iterator index = m_ScheduleList.begin(); index != m_ScheduleList.end(); ++index)
	{

		//index->Tuesday = index->Wednesday = index->Thursday = index->Friday = index->Monday;
		if (index->Monday !=0)
		{
			Event temEvent;
			temEvent.Day = 0;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Monday;

			m_Monday.push_back(temEvent);
		}

		if (index->Tuesday != 0)
		{
			Event temEvent;
			temEvent.Day = 1;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Tuesday;

			m_Tuesday.push_back(temEvent);
		}

		if (index->Wednesday != 0)
		{
			Event temEvent;
			temEvent.Day = 2;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Wednesday;

			m_Wednesday.push_back(temEvent);
		}

		if (index->Thursday != 0)
		{
			Event temEvent;
			temEvent.Day = 3;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Thursday;

			m_Thursday.push_back(temEvent);
		}

		if (index->Friday != 0)
		{
			Event temEvent;
			temEvent.Day = 4;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Friday;

			m_Friday.push_back(temEvent);
		}

		if (index->Saturday != 0)
		{
			Event temEvent;
			temEvent.Day = 5;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Saturday;

			m_Saturday.push_back(temEvent);
		}

		if (index->Sunday != 0)
		{
			Event temEvent;
			temEvent.Day = 6;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Sunday;

			m_Sunday.push_back(temEvent);
		}

		if (index->Holiday != 0)
		{
			Event temEvent;
			temEvent.Day = 7;
			temEvent.Hour = index->Hour;
			temEvent.Minite = index->Minite;
			temEvent.Event_Number = index->Holiday;

			m_Holiday.push_back(temEvent);
		}



	}
	unsigned short TimeBuffer[100];
	int EventNumber=0;
	int i = 0;
	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	for ( i=0;i<(int)m_Monday.size();i++)
	{
		
		TimeBuffer[2 * i] = m_Monday.at(i).Hour;
		TimeBuffer[2 * i+1] = m_Monday.at(i).Minite;
		EventNumber += m_Monday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813, 12);
	write_one(g_tstat_id, 909, EventNumber);
	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Tuesday.size(); i++)
	{
		 
		TimeBuffer[2 * i] = m_Tuesday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Tuesday.at(i).Minite;
		EventNumber += m_Tuesday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813+12*1, 12);
	write_one(g_tstat_id, 910, EventNumber);
	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Wednesday.size(); i++)
	{
		 
		TimeBuffer[2 * i] = m_Wednesday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Wednesday.at(i).Minite;
		EventNumber += m_Wednesday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813 + 12 * 2, 12);
	write_one(g_tstat_id, 911, EventNumber);
	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Thursday.size(); i++)
	{
	 
		TimeBuffer[2 * i] = m_Thursday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Thursday.at(i).Minite;
		EventNumber += m_Thursday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813 + 12 * 3, 12);
	write_one(g_tstat_id, 912, EventNumber);
	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Friday.size(); i++)
	{
		 
		TimeBuffer[2 * i] = m_Friday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Friday.at(i).Minite;
		EventNumber += m_Friday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813 + 12 * 4, 12);
	write_one(g_tstat_id, 913, EventNumber);

	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Saturday.size(); i++)
	{
	 
		TimeBuffer[2 * i] = m_Saturday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Saturday.at(i).Minite;
		EventNumber += m_Saturday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813 + 12 * 5, 12);
	write_one(g_tstat_id, 914, EventNumber);

	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Sunday.size(); i++)
	{
	 
		TimeBuffer[2 * i] = m_Sunday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Sunday.at(i).Minite;
		EventNumber += m_Sunday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813 + 12 * 6, 12);
	write_one(g_tstat_id, 915, EventNumber);
	memset(TimeBuffer, 0xff, sizeof(unsigned short) * 12);
	EventNumber = 0;
	for (i = 0; i < (int)m_Holiday.size(); i++)
	{
	 
		TimeBuffer[2 * i] = m_Holiday.at(i).Hour;
		TimeBuffer[2 * i + 1] = m_Holiday.at(i).Minite;
		EventNumber += m_Holiday.at(i).Event_Number*PowerFour(4, i);
	}
	Write_Multi_short(g_tstat_id, TimeBuffer, 813 + 12 * 7, 12);
	write_one(g_tstat_id, 916, EventNumber);


	AfxMessageBox(_T("Write Successfully"));
}


void CNewTstatSchedulesDlg::OnBnClickedCheckEnableSchedule()
{
	int ret = 0;
	if (product_register_value[MODBUS_SCHEDULE_ON_OFF] == 0)
	{
		ret = write_one(g_tstat_id, MODBUS_SCHEDULE_ON_OFF, 1);
		if (ret > 0)
		{
			product_register_value[MODBUS_SCHEDULE_ON_OFF] = 1;
			((CButton *)GetDlgItem(IDC_CHECK_ENABLE_SCHEDULE))->SetCheck(1);
		} 
	}
	else
	{
		ret = write_one(g_tstat_id, MODBUS_SCHEDULE_ON_OFF, 0);
		if (ret > 0)
		{
			product_register_value[MODBUS_SCHEDULE_ON_OFF] = 0;
			((CButton *)GetDlgItem(IDC_CHECK_ENABLE_SCHEDULE))->SetCheck(0);
		}
	}
	
}


void CNewTstatSchedulesDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	 
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CString temp_cstring;
	long lRow, lCol;

	DWORD dwPos = GetMessagePos();//Get which line is click by user.Set the check box, when user enter Insert it will jump to program dialog
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
	WeeeklyList.ScreenToClient(&point);
	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;
	lvinfo.flags = LVHT_ABOVE;
	int nItem = WeeeklyList.SubItemHitTest(&lvinfo);

	lRow = lvinfo.iItem;
	lCol = lvinfo.iSubItem;


 
		 CSetTimeDlg dlg;
		 if (dlg.DoModal() == IDOK)
		 {
			 CString temp = dlg.m_strTime;
			 Schedule_Node sr;
			 CStringArray aaa;
			 SplitCStringA(aaa, temp, L":");
			 if (aaa.GetSize() >= 2)
			 {
				 sr.Hour = _wtoi(aaa[0]);
				 sr.Minite = _wtoi(aaa[1]);
				 InsertAndUpdate_Schdule(sr);
				 
				 WeeeklyList.InsertItem(WeeeklyList.GetRowCount(), L"");
			 }
			 
			 Fresh_List();

		 }
		 
	 
	
	
	if (lRow < 0)
		return;
	*pResult = 0;
}
