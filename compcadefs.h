#ifndef COMPCADEFS_H
#define COMPCADEFS_H

class ComPcaDefs
{
public:
    static const unsigned char CMD_CONECTAR = 0x01;
    static const unsigned char CMD_DESCONECTAR = 0x02;
    static const unsigned char CMD_ABRIR_PUERTA = 0x03;
    static const unsigned char CMD_BLOQUEAR_PUERTA = 0x04;
    static const unsigned char CMD_DESBLOQUEAR_PUERTA = 0x05;
    static const unsigned char CMD_OPERACION_NORMAL_PUERTA = 0x06;
    static const unsigned char CMD_CONFIGURAR_TIEMPO_ACTIVACION = 0x07;
    static const unsigned char CMD_CONFIGURAR_HORAS_ACTIVACION = 0x08;
    static const unsigned char CMD_AGREGAR_USUARIO = 0x09;
    static const unsigned char CMD_MODIFICAR_USUARIO = 0x2B;
    static const unsigned char CMD_ELIMINAR_USUARIO = 0x0A;
    static const unsigned char CMD_BUSCAR_USUARIO = 0x23;
    static const unsigned char CMD_LEER_HORA_DIA_PCA = 0x0B;
    static const unsigned char CMD_ESTABLECER_HORA_DIA_PCA = 0x0C;
    static const unsigned char CMD_MONITOREO_PCA = 0x0D;
    static const unsigned char CMD_NUMERO_USUARIOS_MDU_PCA = 0x0E;
    static const unsigned char CMD_NUMERO_EVENTOS_PCA = 0x0F;
    static const unsigned char CMD_LEER_EVENTOS_MPCA = 0x10;
    static const unsigned char CMD_AGREGAR_DIA_FESTIVO = 0x11;
    static const unsigned char CMD_CONFIGURAR_HORARIOS_DIAS_FESTIVOS = 0x12;
    static const unsigned char CMD_CONFIGURAR_IN_SENIAL_EMERGENCIA = 0x13;
    static const unsigned char CMD_CONFIGURAR_IN_SENSOR_PRESENCIA_APERTURA_CIERRE = 0x14;
    //static const unsigned char CMD_CONFIGURAR_IN_SENSOR_PRESENCIA_CIERRE = 0x15;
    static const unsigned char CMD_CONFIGURAR_ACTIVACION_SALIDA_SX_RETARDO = 0x16;
    //static const unsigned char CMD_CONFIGURAR_ACTIVACION_SAUXY_SENIAL_EMERGENCIA = 0x17;
    static const unsigned char CMD_CONFIGURAR_ACTIVACION_SAUXY_IN = 0x17;
    static const unsigned char CMD_CONFIGURAR_IN_APERTURA_SX = 0x2C;
    static const unsigned char CMD_BORRAR_HORARIOS = 0x26;
    static const unsigned char CMD_REINICIALIZAR_HORARIOS = 0x2F;
    static const unsigned char CMD_BORRAR_APUNTADORES = 0x24;
    static const unsigned char CMD_BORRAR_MEMORIA = 0x25;
    static const unsigned char CMD_BORRAR_EVENTOS = 0x31;
    static const unsigned char CMD_ACK_EVENTOS = 0x30;
    static const unsigned char CMD_RETRANSMISION_EVENTOS = 0x2D;
    static const unsigned char CMD_PRUEBA_ESCRITURA_MEM = 0x19;
    static const unsigned char CMD_PRUEBA_LECTURA_MEM = 0x20;
    static const unsigned char CMD_TRANSMISION_MAC = 0x2A;
    static const unsigned char CMD_MODO_UNA_PUERTA = 0x27;
    static const unsigned char CMD_MODO_DOS_PUERTAS = 0x28;
    static const unsigned char CMD_MODO_BUSQUEDA_TAG_UHF = 0x38;
    static const unsigned char CMD_SALIR_MODO_BUSQUEDA_TAG_UHF = 0x39;
    static const unsigned char CMD_SOLICITA_TAG_UHF = 0x3A;
    static const unsigned char CMD_MODO_UHF = 0x3C;
    static const unsigned char CMD_SALIR_MODO_UHF = 0x3B;
    static const unsigned char CMD_DELIMITADOR = 0xDF;
    static const unsigned char CMD_HASH_REQUEST = 0x40;
    static const unsigned char CMD_CLEAR_HOLYDAYS = 0x32;

    /*!
     * \brief Declaración de los comandos respuesta empleados en las tramas de comunicación
     */
    static const unsigned char RSP_ERROR_CRC = 0x80;
    static const unsigned char RSP_CONECTAR = 0xFF;
    static const unsigned char RSP_DESCONECTAR = 0xA0;
   // static const unsigned char RSP_DESCONECTAR = 0xFE;  //En el documento viene 0xFE
    static const unsigned char RSP_ABRIR_PUERTA = 0xFD;
    static const unsigned char RSP_BLOQUEAR_PUERTA = 0xFC;
    static const unsigned char RSP_DESBLOQUEAR_PUERTA = 0xFB;
    static const unsigned char RSP_OPERACION_NORMAL_PUERTA = 0xFA;
    static const unsigned char RSP_CONFIGURAR_TIEMPO_ACTIVACION = 0xF9;
    static const unsigned char RSP_CONFIGURAR_HORAS_ACTIVACION = 0xF8;
    static const unsigned char RSP_AGREGAR_USUARIO = 0xF7;
    static const unsigned char RSP_AGREGAR_USUARIO_YA_EXISTE_EN_MEMORIA = 0xDD;
    static const unsigned char RSP_AGREGAR_USUARIO_MEMORIA_LLENA = 0xB6;
    static const unsigned char RSP_ELIMINAR_USUARIO = 0xF6;
    static const unsigned char RSP_ELIMINAR_USUARIO_NO_EXISTE_EN_MEMORIA = 0xE0;
    static const unsigned char RSP_BUSCAR_USUARIO = 0xDF;
    static const unsigned char RSP_BUSCAR_USUARIO_NO_EXISTE_EN_MEMORIA = 0xE0;
    static const unsigned char RSP_MODIFICAR_USUARIO = 0xD6;
    static const unsigned char RSP_MODIFICAR_USUARIO_NO_EXISTE_EN_MEMORIA = 0xE0;
    static const unsigned char RSP_LEER_HORA_DIA_PCA = 0xF5;
    static const unsigned char RSP_ESTABLECER_HORA_DIA_PCA = 0xF4;
    static const unsigned char RSP_AGREGAR_DIA_FESTIVO = 0xA3;
    static const unsigned char RSP_MONITOREO_PCA_NO_UID = 0xA1;
    static const unsigned char RSP_MONITOREO_PCA_UID = 0xF3;
    static const unsigned char RSP_NUMERO_USUARIOS_MDU_PCA = 0xA2;
    static const unsigned char RPS_NUMERO_EVENTOS_PCA = 0xF1;
    static const unsigned char RSP_LEER_EVENTOS_MPCA = 0xF0;
    static const unsigned char RSP_LEER_EVENTOS_INCOMPLETO_NO_ACK = 0xC7;
    static const unsigned char RSP_CONFIGURAR_HORARIOS_DIAS_FESTIVOS = 0xEE;
    static const unsigned char RSP_CONFIGURAR_IN_SENIAL_EMERGENCIA = 0xED;
    static const unsigned char RSP_CONFIGURAR_IN_SENSOR_PRESENCIA_APERTURA_CIERRE = 0xEC;
    //static const unsigned char RSP_CONFIGURAR_IN_SENSOR_PRESENCIA_CIERRE = 0x15;
    static const unsigned char RSP_CONFIGURAR_ACTIVACION_SALIDA_SX_RETARDO = 0xEA;
    //static const unsigned char RSP_CONFIGURAR_ACTIVACION_SAUXY_SENIAL_EMERGENCIA = 0x17;
    static const unsigned char RSP_CONFIGURAR_ACTIVACION_SAUXY_IN = 0xE9;
    static const unsigned char RSP_CONFIGURAR_IN_APERTURA_SX = 0xD5;
    static const unsigned char RSP_BORRAR_HORARIOS = 0xDC;
    static const unsigned char RSP_REINICIALIZAR_HORARIOS = 0xDC;
    static const unsigned char RSP_BORRAR_APUNTADORES = 0xE3;
    static const unsigned char RSP_BORRAR_MEMORIA = 0xDE;
    static const unsigned char RSP_BORRAR_EVENTOS = 0xD0;
    static const unsigned char RSP_ACK_EVENTOS = 0xD1;
    static const unsigned char RSP_RETRANSMISION_EVENTOS = 0xD4;
    static const unsigned char RSP_RETRANSMISION_SIN_LECTURA_PREVIA = 0xC8;
    static const unsigned char RSP_PRUEBA_ESCRITURA_MEM_EXITOSA = 0xE7;
    static const unsigned char RSP_PRUEBA_ESCRITURA_MEM_FALLIDA = 0xE6;
    static const unsigned char RSP_PRUEBA_LECTURA_MEM_EXITOSA = 0xE5;
    static const unsigned char RSP_PRUEBA_LECTURA_MEM_FALLIDA = 0xE4;
    static const unsigned char RSP_TRANSMISION_MAC = 0xD7;
    static const unsigned char RSP_MODO_UNA_PUERTA = 0xDA;
    static const unsigned char RSP_MODO_DOS_PUERTAS = 0xD9;
    static const unsigned char RSP_MODO_BUSQUEDA_TAG_UHF = 0xBF;
    static const unsigned char RSP_SALIR_MODO_BUSQUEDA_TAG_UHF = 0xBE;
    static const unsigned char RSP_SOLICITA_TAG_UHF = 0xBD;
    static const unsigned char RSP_TAG_UHF_NO_DISPONIBLE = 0xBA;
    static const unsigned char RSP_MODO_UHF = 0x38;
    static const unsigned char RSP_SALIR_MODO_UHF = 0xBC;
    static const unsigned char RSP_HASH_REQUEST = 0xB5;
    static const unsigned char RSP_CLEAR_HOLYDAYS = 0xC9;


    static const unsigned char USERS_HASH = 0x00;
    static const unsigned char TIME_TABLES_HASH = 0x01;
    static const unsigned char HOLYDAYS_HASH = 0x02;


    ComPcaDefs();
};

#endif // COMPCADEFS_H
