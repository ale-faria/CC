--- script para populacao inicial e ficticia do banco de dados

use doacoes;

INSERT INTO CategoriaDoItem (idCategoriaDoItem, Nome) VALUES
(1, 'Alimentos'),
(2, 'Higiene'),
(3, 'Roupas');

INSERT INTO Doador (idDoador, Nome, CPF_CNPJ, `E-mail`, Telefone) VALUES
(1, 'João Silva', '12345678901', 'joao@gmail.com', '31999990000'),
(2, 'Empresa Solidária', '12345678000199', 'contato@solidaria.com.br', '3133334444');

INSERT INTO Instituicao (CNPJ_Instituicao, Nome, Endereco, Telefone) VALUES
('11111111000111', 'Paroquia', 'Rua das Flores, 100', '3122223344');

INSERT INTO Receptor (idReceptor, Nome, CPF, Endereco, Composicao_familiar) VALUES
(1, 'Maria Souza', '98765432100', 'Rua da Paz, 45', 'Mãe solteira com 2 filhos'),
(2, 'Carlos Lima', '87654321099', 'Rua do Sol, 80', 'Casado, 3 filhos');

INSERT INTO ItemDoado (idItemDoado, Nome, Descricao, ID_categoria) VALUES
(1, 'Arroz 5kg', 'Pacote de arroz branco tipo 1', 1),
(2, 'Sabonete', 'Sabonete neutro', 2),
(3, 'Camiseta M', 'Camiseta tamanho M', 3);

INSERT INTO Doacao (idDoacao, Data_da_doacao, ID_doador, CNPJ_instituicao) VALUES
(1, '2025-06-01', 1, '11111111000111'),
(2, '2025-06-10', 2, '11111111000111');

INSERT INTO Voluntario (CPF_Voluntario, Nome, Telefone, CNPJ_instituicao) VALUES
('99988877766', 'Ana Paula', '31988887777', '11111111000111'),
('88877766655', 'Ricardo Gomes', '31977776666', '11111111000111');

INSERT INTO TransacaoDeDoacao (idTransacaoDeDoacao, Data_da_entrega, ID_receptor) VALUES
(1, '2025-06-15', 1),
(2, '2025-06-20', 2);

INSERT INTO ItensDaDoacao (ID_doacao, ID_item_doado, Quantidade, Data_de_validade) VALUES
(1, 1, 2, '2026-01-01'),
(1, 2, 5, '2025-12-15'),
(2, 3, 3, NULL);

INSERT INTO ItensDaTransacao (ID_item_doado, ID_transacao, Quantidade) VALUES
(1, 1, 1),
(2, 1, 2),
(3, 2, 2);
