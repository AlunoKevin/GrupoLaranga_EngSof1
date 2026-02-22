PRAGMA foreign_keys = ON;

-- ============================
-- TABELA: usuarios
-- ============================

CREATE TABLE usuarios (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    cpf TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL,
    login TEXT NOT NULL UNIQUE,
    senha TEXT NOT NULL,
    perfil TEXT NOT NULL CHECK (perfil IN ('ADMIN', 'MEDICO', 'ENFERMEIRO'))
);

-- Usuários padrão
INSERT INTO usuarios (nome, cpf, email, login, senha, perfil)
VALUES 
('Administrador', '00000000000', 'admin@clinigest.com', 'admin', '1234', 'ADMIN'),
('Dr. João Silva', '11111111111', 'joao@clinigest.com', 'medico1', '1234', 'MEDICO'),
('Enf. Maria Souza', '22222222222', 'maria@clinigest.com', 'enfermeiro1', '1234', 'ENFERMEIRO');


-- ============================
-- TABELA: consultas (Agendamentos)
-- ============================

CREATE TABLE consultas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    data TEXT NOT NULL,
    hora TEXT NOT NULL,
    paciente_nome TEXT NOT NULL,
    medico_id INTEGER NOT NULL,
    status TEXT DEFAULT 'AGENDADA',
    
    FOREIGN KEY (medico_id) REFERENCES usuarios(id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- Índice para evitar dois agendamentos no mesmo horário para o mesmo médico
CREATE UNIQUE INDEX idx_medico_data_hora
ON consultas (medico_id, data, hora);


-- ============================
-- TABELA: triagens
-- ============================

CREATE TABLE triagens (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    consulta_id INTEGER NOT NULL,
    enfermeiro_id INTEGER NOT NULL,
    pressao TEXT,
    temperatura REAL,
    sintomas TEXT,
    observacoes TEXT,
    
    FOREIGN KEY (consulta_id) REFERENCES consultas(id)
        ON DELETE CASCADE,
        
    FOREIGN KEY (enfermeiro_id) REFERENCES usuarios(id)
        ON DELETE CASCADE
);


-- ============================
-- TABELA: atendimentos
-- ============================

CREATE TABLE atendimentos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    consulta_id INTEGER NOT NULL,
    medico_id INTEGER NOT NULL,
    diagnostico TEXT,
    prescricao TEXT,
    observacoes TEXT,
    data_atendimento TEXT NOT NULL,
    
    FOREIGN KEY (consulta_id) REFERENCES consultas(id)
        ON DELETE CASCADE,
        
    FOREIGN KEY (medico_id) REFERENCES usuarios(id)
        ON DELETE CASCADE
);


-- ============================
-- DADOS DE TESTE
-- ============================

-- Consulta de exemplo
INSERT INTO consultas (data, hora, paciente_nome, medico_id)
VALUES ('2026-02-25', '10:00', 'Carlos Mendes', 2);

-- Triagem de exemplo
INSERT INTO triagens (consulta_id, enfermeiro_id, pressao, temperatura, sintomas)
VALUES (1, 3, '12x8', 36.5, 'Dor de cabeça');

-- Atendimento de exemplo
INSERT INTO atendimentos (consulta_id, medico_id, diagnostico, prescricao, data_atendimento)
VALUES (1, 2, 'Enxaqueca', 'Paracetamol 500mg', '2026-02-25');