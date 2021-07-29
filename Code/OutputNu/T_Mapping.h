#pragma once

//-------------------------------------------------------------------------
/*	��������� long_double ��������� ��� ���������� T-�������.
� ��� �������� ����� �������� ������� � ��������, � ������� ��� ������.
������ ������� ��� ��� ����� ������.
*/
//-------------------------------------------------------------------------
struct long_double
{
	long i;
	double d;
};
//-------------------------------------------------------------------------
// �������� ������ ������������ ��� �������� "�������" ������� �������� �������
// ��� ���������� T-�������
//-------------------------------------------------------------------------
class Btree
{
public:
	long elem_long;
	double elem_double;
	bool visited;
	Btree *left, *right;
	
	Btree();
	Btree(long elem_long, double elem_double);
	~Btree();

	int DeleteTree(Btree *t);
	int Add_Left(long elem_long, double elem_double);
	int Add_Right(long elem_long, double elem_double);
	Btree * visit(std::vector<long_double> *s_t, Btree *t, long j);
};
//--------------------------------------------------------------------------------------------------------------
// ����� T_Mapping_Vec ������ ��� ���������� �-������� ��� ��������� (edge-elements)
// �������������� � ��������� ���� � ������� �����.
//
// ����� ������������ ��������� �������� ������� � ��������������� ������������� 2/hx, 2/hy, 2/hz ����� ����,
// ������� ����� �� ������� � T-������� ������ �� ����� 1, � ��������� ����� �������� ������������.
//--------------------------------------------------------------------------------------------------------------
class T_Mapping_Vec
{
public: 
	T_Mapping_Vec(long (*nver)[14], double (*xyz)[3], long kuzlov, long kpar);
	~T_Mapping_Vec();

	// ������� �������� � ����������� ���������� �������
	long *ig_t; 
	long *jg_t;
	double *gg_t;

	long *ig_s, *jg_s; // ��������� SIGMA (��������������� ��������� ��� T-�������)
	double *s_val;     // ��������, �-��� ����������� ��� ������������ ���� ��������� ��������� ������� T 

	long n_c;  // ����� ����������� ������� (continuous)
	long n_dc; // ����� ��������� ������� (discontinuous)
	long n;    // ����� ������� n = n_c + n_dc

	long kuzlov; // ���-�� ����� � �����
	long kpar;   // ���-�� ����������������
	long (*nver)[14]; // ������ ������������� ������ ������ + ������������ ���� + ��� ��-��
	double (*xyz)[3]; // ���������� ������ (���� ������)

	long (*edges)[2]; // ����, �������� 2-�� ���������
	long (*ed)[25];   // ������ ������������� ������ ������ + ������������ ���� + ��� ��-��  !!!!! �� ������ - ��� �������� ������

	//--------------------------------------------------------------------------------------
	// ��� A-V ����������
	// ��������
	long edges_c;  // ����� ����������� ������� (continuous)
	long edges_dc; // ����� ��������� ������� (discontinuous)
	long edges_all;    // ����� ������� edges_all = edges_c + edges_dc
	// �������
	long nodes_c;  // ����� ����������� ������� (continuous)
	long nodes_dc; // ����� ��������� ������� (discontinuous)
	long nodes_all;    // ����� ������� nodes_all = nodes_c + nodes_dc
	// �����������
	long unk_all;

	long *nvkat;
	long *m_nded;		// m_nded - ������ ��� �������� ������� ����������� (����� � �����)
	long *m_nded_type;	// 0 - ����, 1 - �����
	long (*nvetr)[20];	// �������� ������������� ������ ������ � ������� � ��������� ��������������� m_nded
	// 1-8  - ������ ����� � ������� m_nded
	// 9-20 - ������ ����� � ������� m_nded
	long *nodes_position_in_nded;	// ������� ����� � ������� m_nded
	long *edges_position_in_nded;	// ������� ����� � ������� m_nded
	bool *nodes_earth; // 0 - ���� ����� � �������, 1 - � �����
	int Form_data_A_V(long *nvkat);

	// ������� ������� �������� � ����������� ���������� �������
	long *ig_t_nodes; 
	long *jg_t_nodes;
	double *gg_t_nodes;
	// �������� ������� �������� � ����������� ���������� �������
	long *ig_t_edges; 
	long *jg_t_edges;
	double *gg_t_edges;
	void LoadTmatrices();
	//------------------------------------------------------------------------------------------------------------------------------


	int Enumerate_Edges_In_Nonconforming_Mesh(); // ��������� ���� � ������� ����� (��������� edges, ed)
	int Build_Sigma_Stucture(); // �������� ig_s, jg_s, s_val
	int Build_T_Matrix();       // ��������� ������� T (�������������)

	// ������ ������� ������� ����, ����������� ��� ���������� 
	// ����������� ��������� ��������� ������� j
	Btree* Build_Sequence(long e, double value);

	// ������������ ������ ����� �� ���� ����� (� � ������������, � � ��������������)
	int CalcValuesAll(double *v3_c, double *v3_all);
	int CalcValuesAll(double *v3); // ���������� � �����

	int UnloadVMesh();
};
//--------------------------------------------------------------------------------------------------