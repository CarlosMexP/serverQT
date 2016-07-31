#ifndef CRC_H
#define CRC_H

/**
 * \author Aldo Gustavo Orozco Lugo
 * \date Enero-2014
 */

typedef  unsigned short int uint16;

/** @brief La función inserta_CRC calcula e inserta el CRC en la trama a transmitir
    @param unsigned char* trama: el arreglo con los bytes de información de la
    trama a transmitir.
    @param unsigned char num_bytes_trama: variable que indica el número de bytes de
    información existentes en el arreglo trama. Es importante asegurarse que el arreglo
    trama tiene el espacio suficiente para incluir los dos bytes adicionales correspondientes
    al CRC, los cuales se insertan al final del arreglo.
*/
void inserta_CRC(unsigned char* trama, uint16 num_bytes_trama );


/** @brief La función verifica_CRC se encarga de probar si la trama fue recibida correctamente.
    @param unsigned char *trama_con_crc: La trama recibida incluyendo el CRC
    @param unsigned char num_bytes_trama_con_crc: El número de bytes de la trama incluyendo
    los bytes correspondientes al CRC.
    @return unsigned_char crc_valido: La función regresa 1 se la trama se recibió correctamente
    y regresa un 0 si fue recibida con error.
*/
unsigned char verifica_CRC(unsigned char* trama_con_crc, uint16 num_bytes_trama_con_crc);

#endif  
