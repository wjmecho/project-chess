#ifndef POSITION_H
#define POSITION_H


class Position     //���ڷ������������
{
    public:
        Position();
//        Position(const Position &p);     //�������캯����
        virtual ~Position();
        void saisirposition();            //��������
        void afficherposition() const;    //��ʾ����
        void setligne(char a);             //ȷ���к�
        void setcolonne(int c);            //ȷ���к�
        int getcolonne() const;            //�����к�
        char getligne() const;             //�����к�
        bool operator==(const Position &p) const;    //�ж��������Ƿ����
        Position & operator=(const Position &p);     //����

    protected:
    private:
        char l;             //�к�
        int  c;
//        int dir[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};            //�к�


};

#endif // POSITION_H
