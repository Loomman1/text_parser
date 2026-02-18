#include "Headers.h"
#include <iostream>
#include <fstream>


bool o_digit(char p)
{
	bool vz = false;
	if (p > 47 && p < 58)
	{
		vz = true;
	}
	return vz;
}

//класс imusch
imusch::imusch()
{
	NomInvKart = 0;          InvNomer = 0;
	Nazv = "NoNazv";         debZatr = 0;
	dateVvod = "00/0000";    balPrice = 0;
	sumAmort = 0;            nakop = 0;
};
imusch::imusch(string p)
{

	if (p.length() > 50)
	{
		int pos = 0;
		NomInvKart = atoi(p.substr(0, 6).c_str());
		InvNomer = atoi(p.substr(7, 7).c_str());
		Nazv = p.substr(13, 49);

		pos = p.find("/1");
		if (pos < 3)pos = p.find("/2");
		debZatr = atoi(p.substr(pos - 5, 2).c_str());
		dateVvod = p.substr(pos - 2, 7);
		balPrice = atof(p.substr(pos + 5, 15).c_str());
		sumAmort = atof(p.substr(pos + 20, 12).c_str());
		nakop = atof(p.substr(pos + 32, 14).c_str());

	}
	else
	{
		NomInvKart = 0;          InvNomer = 0;
		Nazv = "NoNazv";         debZatr = 0;
		dateVvod = "00/0000";    balPrice = 0;
		sumAmort = 0;            nakop = 0;
	}
};
imusch::~imusch() {};
imusch::imusch(imusch& o)
{

	NomInvKart = o.NomInvKart;
	InvNomer = o.InvNomer;
	Nazv = o.Nazv;
	debZatr = o.debZatr;
	dateVvod = o.dateVvod;
	balPrice = o.balPrice;
	sumAmort = o.sumAmort;
	nakop = o.nakop;
}

void imusch::print()
{
	cout << " >";
	cout.width(6);
	cout << NomInvKart;
	cout.width(6);
	cout << InvNomer;
	cout << Nazv;
	cout.width(2);
	cout << debZatr;
	cout.width(10);
	cout << dateVvod;
	cout.precision(2);
	cout << fixed;
	cout.width(12);
	cout << balPrice;
	cout.width(9);
	if (sumAmort != 0)
	{
		cout << sumAmort;
	}
	else cout << "        ";
	cout.width(12);
	cout << nakop;
	cout.width(12);
	if ((balPrice - nakop) > 0)
	{
		cout << balPrice - nakop << endl;
	}
	else cout << "      " << endl;
}
int imusch::get_code() { return NomInvKart; }
double imusch::getBalPr() { return balPrice; }
double imusch::getAmort() { return sumAmort; }
double imusch::getNakop() { return nakop; }




//класс typeImusch
typeImusch::typeImusch() { nomIm = 0; Nazv = "NoNazv"; Nmax = 70; n = 0; MiIm = new imusch * [Nmax]; };
typeImusch::typeImusch(string p)
{
	if (p.length() > 10)
	{
		nomIm = atoi(p.substr(5, 3).c_str());
		Nazv = p.substr(8, 50);
	}
	else
	{
		nomIm = 0;
		Nazv = "NoFIO";
	}
	Nmax = 70;
	n = 0;
	MiIm = new imusch * [Nmax];
};
typeImusch::typeImusch(int p1, string p2)
{
	nomIm = p1;
	Nazv = p2;
	Nmax = 70;
	n = 0;
	MiIm = new imusch * [Nmax];
}
typeImusch::~typeImusch() { delete[]MiIm; };
typeImusch::typeImusch(typeImusch& o)
{
	nomIm = o.nomIm;
	Nazv = o.Nazv;
	Nmax = o.Nmax;
	n = o.n;
	MiIm = new imusch * [Nmax];
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			MiIm[i] = new imusch(*o.MiIm[i]);
		}
}

imusch* typeImusch::getImByInd(int ind)
{
	return MiIm[ind];
}
string typeImusch::getNazvImType()
{
	return Nazv;
}

double typeImusch::summa(int flag)
{
	double vz = 0;
	if (flag == 1)
	{
		for (int i = 0; i < n; i++)
		{
			vz += MiIm[i]->getBalPr();
		}
	}
	else
		if (flag == 2)
		{
			for (int i = 0; i < n; i++)
			{
				vz += MiIm[i]->getAmort();
			}
		}
		else
			if (flag == 3)
				for (int i = 0; i < n; i++)
				{
					vz += MiIm[i]->getNakop();
				}

	return vz;
}
int typeImusch::getN()
{
	return n;
}
int typeImusch::get_imusch_code(int ind)
{
	return MiIm[ind]->get_code();
}
int typeImusch::getNomImType()
{
	return nomIm;
}
int typeImusch::find_imusch(int inv_nomer)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (inv_nomer == MiIm[i]->get_code())
			return i;
	}
	return -1;
}

void typeImusch::add_new_imusch(imusch& im)
{
	MiIm[n] = new imusch(im);
	n++;
}
void typeImusch::print()
{
	if (n > 0)
	{
		cout.fill(' - ');
		cout << "\n" << "<-----" << nomIm << "  " << Nazv << "  (" << n << "/" << Nmax << ") Edinits imuschestva" << "------------->" << endl;

		for (int i = 0; i < n; i++)
		{
			MiIm[i]->print();
		}
	}
}
void typeImusch::add_imusch(string p)
{
	if (n < Nmax)
	{
		MiIm[n] = new imusch(p);
		n++;
	}
}




//класс litso
litso::litso() { TabNom = 0;  FIO = "NoFIO"; Nmax = 35; n = 0; Mi = new typeImusch * [Nmax]; };
litso::litso(string p)
{
	if (p.length() > 10)
	{
		TabNom = atoi(p.substr(4, 3).c_str());
		FIO = p.substr(7, 30);
	}
	else
	{
		TabNom = 0;
		FIO = "NoFIO";
	}
	n = 0;
	Nmax = 35;
	Mi = new typeImusch * [Nmax];
};
litso::litso(int tab, string fio)
{
	TabNom = tab;
	FIO = fio;
	Nmax = 35; n = 0; Mi = new typeImusch * [Nmax];
}
litso::~litso() { delete[]Mi; };
litso::litso(litso& o)
{
	TabNom = o.TabNom;
	FIO = o.FIO;
	Nmax = o.Nmax;
	n = o.n;
	Mi = new typeImusch * [Nmax];
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			Mi[i] = new typeImusch(*o.Mi[i]);
		}
}

typeImusch** litso::getMi()
{
	return Mi;
}
typeImusch* litso::get_Tip_imusch(int ind)
{
	return Mi[ind];
}
typeImusch* litso::getlastType()
{
	return Mi[n - 1];
}
imusch* litso::getImusch(int indType, int IndImusch)
{
	return Mi[indType]->getImByInd(IndImusch);
}
string litso::get_name_Type(int j) {

	if (j < n)
		return Mi[j]->getNazvImType();
}
string litso::getFio()
{
	return FIO;
}

int litso::getTabNom()
{
	return TabNom;
}
int litso::getN()
{
	return n;
}
int litso::getNimusch(int ind)
{
	return Mi[ind]->getN();
}
int litso::get_code_Type(int j) {

	if (j < n)
		return Mi[j]->getNomImType();
	else return -1;
}
int litso::find_i_type(int type)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (Mi[i]->getNomImType() == type)
			return i;
	}
	return -1;
}
int litso::findImusch(int ind, int inv_nomer_imuschestva)
{
	int vz = 0;
	vz = Mi[ind]->find_imusch(inv_nomer_imuschestva);
	return vz;
}

void litso::add_new_imusch(int indType, imusch newImusch)
{
	Mi[indType]->add_new_imusch(newImusch);
}
void litso::dellastType()
{
	n--;
}
void litso::print()
{
	if (n > 0)
	{cout << endl << TabNom << "  " << FIO << "  (" << n << "/" << Nmax << ") Vidov imuschestva" << endl;
		double sum1 = 0, sum2 = 0, sum3 = 0;

		for (int i = 0; i < n; i++)
		{
			Mi[i]->print();
			sum1 += Mi[i]->summa(1);
			sum2 += Mi[i]->summa(2);
			sum3 += Mi[i]->summa(3);
		}
		cout << "\n> Summarno po litsu " << FIO << "Poluchim:\n>Balansovaya stoimost=" << sum1 << "\n>Summa amortizatsii = " << sum2 << "\n>Nakoplenniy iznos = " << sum3 << "\n>Ostatochnaya stoimost = " << sum1 - sum3 << endl;

	}
}
void litso::add_type(string p)
{
	if (n < Nmax)
	{
		Mi[n] = new typeImusch(p);
		n++;
	}
}
void litso::add_imusch(string p)
{
	if (n < Nmax)
	{
		Mi[n - 1]->add_imusch(p);
	}
}
void litso::add_type_imusch(typeImusch& p1)
{
	Mi[n] = new typeImusch(p1);
	n++;
}


//класс dok
dok::dok()
{
	N_per = "Net perioda";
	per = "      ";
	Nmax = 20;
	n = 0;
	Ml = new litso * [Nmax];
}

dok::dok(const dok& o)
{
	N_per = o.N_per;
	per = o.per;
	Nmax = o.Nmax;
	n = o.n;
	Ml = new litso * [Nmax];
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			Ml[i] = new litso(*o.Ml[i]);
		}
}

dok::dok(string f_name)
{
	ifstream f(f_name);
	string a;
	Nmax = 20;
	Ml = new litso * [Nmax];
	if (f.is_open())
	{
		int fl = 0, fl_litso = 0, i = 0, pos, pos1;
		string p, z;
		while (!f.eof())
		{
			getline(f, p);
			i++;
			pos = p.find(".N ");
			if (pos >= 0)
			{
				if (fl == 0)
				{
					getline(f, p);
					getline(f, p);
					N_per = p.substr(53, 12);
					fl = 1;
				}
				pos = p.find(". ");

			}
			else
			{
				pos1 = p.find("->");
				if (pos1 > 5)
				{
					fl_litso = 0;
				}
				else
				{
					if (p.length() > 10)
					{
						z = p.substr(0, 5).c_str();
						if (fl_litso == 0)
						{
							if ((z == "     ") && (o_digit(p[6]) == true))
							{
								Ml[n] = new litso(p);
								n++;
								fl_litso = 1;
							}
						}
						else
						{
							if ((o_digit(p[5]) == true) && (o_digit(p[12]) == true))
							{
								Ml[n - 1]->add_imusch(p);
							}
							else
								if ((o_digit(p[6]) == true))
								{
									Ml[n - 1]->add_type(p);
								}
						}
					}
				}
			}

		}
	}
	else
	{
		N_per = "Net perioda";
		per = "      ";

		n = 0;
		Ml = new litso * [Nmax];
	}
}

void dok::add_litso(litso p)
{
	if (n < Nmax)
	{
		Ml[n] = new litso(p);
		n++;
	}
}

void dok::del()
{
	n--;
}

dok::~dok()
{
	if (n > 0)
		for (int i = 0; i < n; i++)
			delete Ml[i];
	delete[]Ml;
}

void dok::print()
{
	cout << "\n" << "\t\t " << N_per << "  " << per << "  (" << n << "/" << Nmax << ") Otvetstvennih lits" << endl;
	if (n > 0)
	{
		cout << "------------------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "|Nomer  |Inven|                                             | Debet| Data  |Balansovaya|  Summa  |Nakoplenniy|Ostatochn |" << endl;
		cout << "|inv.   |tarn.|                  NAIMENOVANIE               |zatrat| vvoda |stoimost   |  amort  |   iznos   |stoim na  |" << endl;
		cout << "|kart.  |nomer|                                             |      |v expl |           | za mes  |           | kon per  |" << endl;
		cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;

		for (int i = 0; i < n; i++)
		{
			Ml[i]->print();
		}
	}
	else {
		cout << "\t\t\t---------->!!!CHANGES NOT FOUND!!!<----------" << endl;
	}
}

int dok::findLitso(int tabl)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (Ml[i]->getTabNom() == tabl)
			return i;
	}
	return -1;
}

dok dok::operator=(dok o)
{
	if (this != &o)
	{
		if (n > 0)
			for (int i = 0; i < n; i++)
				delete Ml[i];
		delete[]Ml;

		N_per = o.N_per;
		per = o.per;
		Nmax = o.Nmax;
		n = o.n;
		Ml = new litso * [Nmax];
		if (n > 0)
			for (int i = 0; i < n; i++)
			{
				Ml[i] = new litso(*o.Ml[i]);
			}
	}
	return *this;
}

dok dok::operator-(dok o)
{
	dok tmp;
	tmp.N_per = N_per + ", " + o.N_per;
	tmp.per = per + ", " + o.per;
	int i = 0, j = 0, k = 0, l = 0, z = 0, i_litso, index_imusch;
	int index_typa = 0;
	if (n > 0)
	{
		for (i = 0; i < o.n; i++)
		{
			i_litso = findLitso(o.Ml[i]->getTabNom()); 
			if (i_litso < 0)
			{
				tmp.add_litso(*o.Ml[i]);
				k++;
			}
			else
			{
				litso lit(Ml[i_litso]->getTabNom(), Ml[i_litso]->getFio());
				tmp.add_litso(lit);
				for (j = 0; j < o.Ml[i]->getN(); j++)
				{
					int code_type = o.Ml[i]->get_code_Type(j);
					index_typa = Ml[i_litso]->find_i_type(code_type);
					if (index_typa < 0)
					{
						typeImusch imm(*o.Ml[i]->get_Tip_imusch(j));
						tmp.Ml[k]->add_type_imusch(imm);
						z++;
					}
					else
					{
						string type_name = o.Ml[i]->get_name_Type(j);
						typeImusch Timm(code_type, type_name);
						tmp.Ml[k]->add_type_imusch(Timm);
						for (l = 0; l < o.Ml[i]->getNimusch(j); l++)
						{
							int codeImusch = o.Ml[i]->get_Tip_imusch(j)->get_imusch_code(l);
							index_imusch = Ml[i_litso]->findImusch(index_typa, codeImusch);
							if (index_imusch < 0)
							{
								imusch im(*o.Ml[i]->getImusch(j, l));
								tmp.Ml[k]->add_new_imusch(z, im);
							}
						}
						z++;
					}
					if (tmp.Ml[k]->getlastType()->getN() <= 0)
					{
						tmp.Ml[k]->dellastType();
						z--;
					}
				}
				k++;
			}
			if (tmp.Ml[k - 1]->getN() <= 0)
			{
				tmp.del();
				k--;
			}
		}
	}
	return tmp;
}

dok dok::operator+(dok o)
{
	return o - *this;
}