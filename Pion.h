#ifndef PION_H
#define PION_H

#include <Piece.h>


class Pion : public Piece        //���ӵ�������  ��
{
    public:
        Pion();
        virtual ~Pion();
        void setisDame(bool res);

//        void movepion();         //������������ƶ���      �������߷���һ��
//        void moveordinateur();   //�����ƶ���      ��Ŀǰֻ�����д��д  ����һЩ���� ���� Ҫ��ָ߼��ͳ��� ����Ҫ������� = =||���ѡ�������
    protected:
    private:

};

#endif // PION_H
