#include "util.hpp"

QString toString(const QByteArray &byteArray)
{
    QString str;
    int size = byteArray.size();

    for(int i = 0; i < size; i++)
    {
        str += QString::number((uchar)byteArray.at(i), 16).rightJustified(2, '0').toUpper();
    }

    return str;
}
