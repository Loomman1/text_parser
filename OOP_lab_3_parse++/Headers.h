#pragma once
#include <string>
using namespace std;

class imusch
{
private:
	int NomInvKart;
	int InvNomer;
	string Nazv;
	int debZatr;
	string dateVvod;
	double balPrice;
	double sumAmort;
	double nakop;


public:
	imusch();
	imusch(string);
	~imusch();

	imusch(imusch&);
	
	int get_code();
	double getBalPr();
	double getAmort();
	double getNakop();
	void print();
};


class typeImusch
{
private:
	int nomIm;
	string Nazv;
	int Nmax;
	int n;
	imusch** MiIm;
public:

	typeImusch();
	typeImusch(string );
	typeImusch(int, string);
	~typeImusch();
	typeImusch(typeImusch&);

	imusch* getImByInd(int);
	string getNazvImType();

	double summa(int);

	int getN();
	int get_imusch_code(int);
	int getNomImType();
	int find_imusch(int);
	
	void print();
	void add_imusch(string);
	void add_new_imusch(imusch&);
};


class litso
{
private:
	int TabNom;
	string FIO;
	int Nmax;
	int n;
	typeImusch** Mi;


public:
	litso();
	litso(string);
	litso(int, string);
	~litso();
	litso(litso&);

	imusch* getImusch(int, int);

	typeImusch* get_Tip_imusch(int);
	typeImusch* getlastType();
	typeImusch** getMi();

	string getFio();
	string get_name_Type(int);

	int find_i_type(int);
	int findImusch(int, int);
	int getTabNom();
	int getN();
	int getNimusch(int);
	int get_code_Type(int);
	
	void print();
	void add_type(string);
	void add_type_imusch(typeImusch&);
	void add_imusch(string);
	void add_new_imusch(int, imusch);
	void dellastType();
};


class dok
{
private:
	string N_per;
	string per;
	int Nmax;
	int n;
	litso** Ml;

public:

	dok();
	dok(const dok&);
	dok(string);
	~dok();

	int findLitso(int);
	void print();
	void add_litso(litso);
	void del();

	dok operator=(dok);
	dok operator-(dok);
	dok operator+(dok);
};