#ifndef SQLCONSULTAREPOSITORY_H
#define SQLCONSULTAREPOSITORY_H

#include <QSqlDatabase>
#include <QList>
#include <QDate>
#include <string> 

#include <interfaces/repositories/IConsultaRepository.h>

class SqlConsultaRepository : public IConsultaRepository
{
public:
    explicit SqlConsultaRepository(QSqlDatabase database);


    bool salvar(const Consulta& consulta) override;
    QList<Consulta> listarPorData(const QDate& data) override;
    bool atualizarStatus(int id, std::string status) override;

private:
    QSqlDatabase db;
};

#endif // SQLCONSULTAREPOSITORY_H