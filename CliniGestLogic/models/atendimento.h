#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <QString>

class Atendimento {
public:
    Atendimento(int idTriagem = 0, QString diagnostico = "", QString prescricao = "", 
                QString exames = "", QString observacoes = "")
        : m_id(0), m_idTriagem(idTriagem), m_diagnostico(diagnostico), 
          m_prescricao(prescricao), m_exames(exames), m_observacoes(observacoes) {}

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    int idTriagem() const { return m_idTriagem; } 
    void setIdTriagem(int id) { m_idTriagem = id; }

    QString diagnostico() const { return m_diagnostico; }
    void setDiagnostico(const QString &d) { m_diagnostico = d; }

    QString prescricao() const { return m_prescricao; }
    void setPrescricao(const QString &p) { m_prescricao = p; }

    QString exames() const { return m_exames; }
    void setExames(const QString &e) { m_exames = e; }

    QString observacoes() const { return m_observacoes; }
    void setObservacoes(const QString &obs) { m_observacoes = obs; }

private:
    int m_id;
    int m_idTriagem; 
    QString m_diagnostico;
    QString m_prescricao;
    QString m_exames;
    QString m_observacoes;
};

#endif // ATENDIMENTO_H