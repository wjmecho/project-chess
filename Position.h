#ifndef POSITION_H
#define POSITION_H


class Position     //用于方便表达坐标的类
{
    public:
        Position();
//        Position(const Position &p);     //拷贝构造函数？
        virtual ~Position();
        void saisirposition();            //输入坐标
        void afficherposition() const;    //显示坐标
        void setligne(char a);             //确定行号
        void setcolonne(int c);            //确定列号
        int getcolonne() const;            //返回列号
        char getligne() const;             //返回行号
        bool operator==(const Position &p) const;    //判断两坐标是否相等
        Position & operator=(const Position &p);     //拷贝

    protected:
    private:
        char l;             //行号
        int  c;
//        int dir[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};            //列号


};

#endif // POSITION_H
