// ���������� ������ Num
class Num
{
	// ������������� ���������� x � y
	int x, y;
	// ����������� ������ � ����������� in_x � in_y
public:	
	Num(int in_x, int in_y);
	// ����� ��� ������ �������� x � y (const ��������, ��� ����� �� �������� ��������� �������)
	void print() const;
	// ����� ��� ���������� �������� �������� ����� (����� �� �������� ��������� �������)
	void math() const;
};