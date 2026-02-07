#include "SqlConsultaRepository.h"

SqlConsultaRepository::SqlConsultaRepository(QSqlDatabase database)
    : db(database)
{
}

bool SqlConsultaRepository::salvar(const Consulta& consulta)
{
    Q_UNUSED(consulta);
    // TODO: implement real SQL logic
    return true;
}

QList<Consulta> SqlConsultaRepository::listarPorData(const QDate& data)
{
    Q_UNUSED(data);
    // TODO: implement real SQL logic
    return {};
}
