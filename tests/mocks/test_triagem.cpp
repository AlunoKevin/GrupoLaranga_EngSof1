#include <QtTest>
#include "../CliniGestLogic/services/servicotriagem.h"
#include "mocks/MockTriagemRepository.h"

class TestTriagem : public QObject
{
    Q_OBJECT

private slots:
    void test_registrar_triagem_valida() {
        // Um mock de repositório e dados de triagem válidos
        MockTriagemRepository* mockRepo = new MockTriagemRepository();
        ServicoTriagem servico(mockRepo);
        Triagem t("12/8", 36.5, 70.0, 1); // Pressão, Temp, Peso, Urgência

        // Chamamos o serviço para registrar
        bool resultado = servico.registrarTriagem(t);

        // O registro deve ser bem sucedido e estar no mock
        QVERIFY(resultado == true);
        QCOMPARE(mockRepo->triagensSalvas.size(), 1);
        
        delete mockRepo;
    }

    void test_validar_temperatura_perigosa() {
        // Uma temperatura inválida
        MockTriagemRepository* mockRepo = new MockTriagemRepository();
        ServicoTriagem servico(mockRepo);
        Triagem t("12/8", 55.0, 70.0, 4);

        // Tentamos registrar
        bool resultado = servico.registrarTriagem(t);

        // O serviço deve recusar (retornar false)
        QVERIFY(resultado == false);
        
        delete mockRepo;
    }
};

QTEST_APPLESS_MAIN(TestTriagem)
#include "test_triagem.moc"