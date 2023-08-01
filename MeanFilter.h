#pragma once

using namespace std;


class CMeanFilter
{
public:
	CMeanFilter();
	CMeanFilter(int Window, long lenth);
	~CMeanFilter();

	void setWindowSize(int Window);
	void setLenth(long lenth);

	int getWindowSize();
	long getlenth();

	void mean(double* target);

private:
	int windowsize;
	int position;
	long lenthofarray;

};

