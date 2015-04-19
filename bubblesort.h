/*****************************************************/
/*         冒泡排序工具类                              */
/*      Ming.Wan      2015-4-19                      */
/*****************************************************/
#ifndef _WAN_BUBBLE_SORT_H_
#define _WAN_BUBBLE_SORT_H_

namespace wan{
	class BubbleSort
	{
	private: 
		BubbleSort(){};
		~BubbleSort(){};
	public:
		/**
		 *冒泡排序的简单实现
		*/
		static void Sort(double *pData,int count);
	};
};


#endif //_WAN_BUBBLE_SORT_H_