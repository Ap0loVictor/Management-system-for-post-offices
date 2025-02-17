#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Veiculos
{
    int veiculo_ID;
    char tipoVeiculo[20];
    float cargaVeiculo;
    char statusVeiculo[10];
};

struct Entregas
{
    int entrega_ID;
    char origem[100];
    char destino[100];
    float tempoEstimado;
};

struct Funcionarios
{
    int funcionario_ID;
    char nomeFuncionario[50];
};

struct Clientes
{
    int cliente_ID;
    char nomeCliente[50];
    char endereco[100];
    char tipoServico[20];
};

int pegarUltimoId(const char *arquivoDaEntidade)
{
    FILE *arquivoId = fopen(arquivoDaEntidade, "r");
    if (arquivoId == NULL)
    {
        arquivoId = fopen(arquivoDaEntidade, "w");
        if (arquivoId == NULL)
        {
            printf("Erro ao criar o arquivo");
            system("Pause");
            exit(1);
        }
        fprintf(arquivoId, "0");
        fclose(arquivoId);
        return 0;
    }
    int ultimo_id;
    fscanf(arquivoId, "%d", &ultimo_id);
    fclose(arquivoId);
    return ultimo_id;
}
void atualizarId(const char *arquivoDaEntidade, int novo_id)
{
    FILE *arquivoId = fopen(arquivoDaEntidade, "w");
    if (arquivoId == NULL)
    {
        printf("Erro ao modificar o arquivo para salvar o ID.");
        system("Pause");
        exit(1);
    }
    fprintf(arquivoId, "%d", novo_id);
    fclose(arquivoId);
}

void cadastrarVeiculo(struct Veiculos veiculo)
{
    FILE *arquivoVeiculos = fopen("Veiculos.txt", "a");
    if (arquivoVeiculos == NULL)
    {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }
    fprintf(arquivoVeiculos, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
            veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
    fclose(arquivoVeiculos);
    printf("\nAs informacoes do veiculo foram salvas no sistema!\n");
}

void cadastrarEntrega(struct Entregas entrega)
{
    FILE *arquivoEntregas = fopen("Entregas.txt", "a");
    if (arquivoEntregas == NULL)
    {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }
    fprintf(arquivoEntregas, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
            entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
    fclose(arquivoEntregas);
    printf("\nAs informacoes da entrega foram salvas no sistema!\n");
}

void cadastrarFuncionario(struct Funcionarios funcionario)
{
    FILE *arquivoFuncionarios = fopen("Funcionarios.txt", "a");
    if (arquivoFuncionarios == NULL)
    {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }
    fprintf(arquivoFuncionarios, "ID do Funcionário: %d\nNome: %s\n",
            funcionario.funcionario_ID, funcionario.nomeFuncionario);
    fclose(arquivoFuncionarios);
    printf("\nAs informacoes do funcionario foram salvas no sistema!\n");
}

void cadastrarCliente(struct Clientes cliente)
{
    FILE *arquivoClientes = fopen("Clientes.txt", "a");
    if (arquivoClientes == NULL)
    {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }
    fprintf(arquivoClientes, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
            cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
    fclose(arquivoClientes);
    printf("\nAs informacoes do cliente foram salvas no sistema!\n");
}

void adicionarVeiculo(struct Veiculos *veiculo)
{
    int id_veiculo = pegarUltimoId("IdVeiculo.txt") + 1;
    atualizarId("idVeiculo.txt", id_veiculo);
    veiculo->veiculo_ID = id_veiculo;

    printf("Tipo de veiculo: ");
    getchar(); 
    fgets(veiculo->tipoVeiculo, sizeof(veiculo->tipoVeiculo), stdin);
    veiculo->tipoVeiculo[strcspn(veiculo->tipoVeiculo, "\n")] = 0; // Remove o '\n'

    printf("Carga maxima (em kg): ");
    scanf("%f", &veiculo->cargaVeiculo);
    getchar();

    printf("Status (disponivel/ocupado): ");
    fgets(veiculo->statusVeiculo, sizeof(veiculo->statusVeiculo), stdin);
    veiculo->statusVeiculo[strcspn(veiculo->statusVeiculo, "\n")] = 0; 
}


void adicionarEntrega(struct Entregas *entrega)
{
    int id_entrega = pegarUltimoId("idEntrega.txt") + 1;
    atualizarId("idEntrega.txt", id_entrega);
    entrega->entrega_ID = id_entrega;

    printf("Origem: ");
    getchar(); // Limpa o buffer antes de fgets
    fgets(entrega->origem, sizeof(entrega->origem), stdin);
    entrega->origem[strcspn(entrega->origem, "\n")] = '\0'; // Remove o '\n'

    printf("Destino: ");
    fgets(entrega->destino, sizeof(entrega->destino), stdin);
    entrega->destino[strcspn(entrega->destino, "\n")] = '\0'; // Remove o '\n'

    printf("Tempo estimado (em horas): ");
    scanf("%f", &entrega->tempoEstimado);
    getchar(); // Evita problemas na leitura do próximo campo
}


void adicionarFuncionario(struct Funcionarios *funcionario)
{
    int id_funcionario = pegarUltimoId("idFuncionarios.txt") + 1;
    atualizarId("idFuncionarios.txt", id_funcionario);
    funcionario->funcionario_ID = id_funcionario;

    printf("Nome: ");
    getchar();
    fgets(funcionario->nomeFuncionario, sizeof(funcionario->nomeFuncionario), stdin);
    funcionario->nomeFuncionario[strcspn(funcionario->nomeFuncionario, "\n")] = '\0'; // Remove o '\n' do final
}


void adicionarCliente(struct Clientes *cliente)
{
    int id_cliente = pegarUltimoId("idClientes.txt") + 1;
    atualizarId("idClientes.txt", id_cliente);
    cliente->cliente_ID = id_cliente;

    printf("Nome: ");
    fgets(cliente->nomeCliente, sizeof(cliente->nomeCliente), stdin);
    cliente->nomeCliente[strcspn(cliente->nomeCliente, "\n")] = '\0';

    printf("Endereco: ");
    fgets(cliente->endereco, sizeof(cliente->endereco), stdin);
    cliente->endereco[strcspn(cliente->endereco, "\n")] = '\0';

    printf("Tipo de serviço: ");
    fgets(cliente->tipoServico, sizeof(cliente->tipoServico), stdin);
    cliente->tipoServico[strcspn(cliente->tipoServico, "\n")] = '\0';
}

void deletarVeiculo(int veiculo_ID)
{
    FILE *arquivoVeiculos = fopen("Veiculos.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");

    if (arquivoVeiculos == NULL || arquivoTemp == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        system("Pause");
        exit(1);
    }

    struct Veiculos veiculo;
    int encontrado = 0;

    while (fscanf(arquivoVeiculos, "ID do Veículo: %d\n", &veiculo.veiculo_ID) == 1)
    {
        fscanf(arquivoVeiculos, "Tipo: %[^\n]\n", veiculo.tipoVeiculo);
        fscanf(arquivoVeiculos, "Carga: %f Kg\n", &veiculo.cargaVeiculo);
        fscanf(arquivoVeiculos, "Status: %[^\n]\n", veiculo.statusVeiculo);

        if (veiculo.veiculo_ID != veiculo_ID)
        {
            fprintf(arquivoTemp, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                    veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
        }
        else
        {
            encontrado = 1;
        }
    }

    fclose(arquivoVeiculos);
    fclose(arquivoTemp);

    if (encontrado)
    {
        if (remove("Veiculos.txt") == 0)
        {
            if (rename("Temp.txt", "Veiculos.txt") == 0)
            {
                printf("Veículo deletado com sucesso.\n");
            }
            else
            {
                printf("Erro ao renomear arquivo.\n");
            }
        }
        else
        {
            printf("Erro ao remover o arquivo original.\n");
        }
    }
    else
    {
        remove("Temp.txt");
        printf("Veículo não encontrado.\n");
    }
}


void deletarEntrega(int entrega_ID)
{
    FILE *arquivoEntregas = fopen("Entregas.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");

    if (arquivoEntregas == NULL || arquivoTemp == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        system("Pause");
        exit(1);
    }

    struct Entregas entrega;
    int encontrado = 0;

    while (fscanf(arquivoEntregas, "ID da Entrega: %d\n", &entrega.entrega_ID) == 1)
    {
        fscanf(arquivoEntregas, "Origem: %[^\n]\n", entrega.origem);
        fscanf(arquivoEntregas, "Destino: %[^\n]\n", entrega.destino);
        fscanf(arquivoEntregas, "Tempo Estimado: %f Horas\n", &entrega.tempoEstimado);

        if (entrega.entrega_ID != entrega_ID)
        {
            fprintf(arquivoTemp, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
                    entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
        }
        else
        {
            encontrado = 1;
        }
    }

    fclose(arquivoEntregas);
    fclose(arquivoTemp);

    if (encontrado)
    {
        if (remove("Entregas.txt") == 0)
        {
            if (rename("Temp.txt", "Entregas.txt") == 0)
            {
                printf("Entrega deletada com sucesso.\n");
            }
            else
            {
                printf("Erro ao renomear arquivo.\n");
            }
        }
        else
        {
            printf("Erro ao remover o arquivo original.\n");
        }
    }
    else
    {
        remove("Temp.txt");
        printf("Entrega não encontrada.\n");
    }
}

void deletarFuncionario(int funcionario_ID)
{
    FILE *arquivoFuncionarios = fopen("Funcionarios.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");

    if (arquivoFuncionarios == NULL || arquivoTemp == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        system("Pause");
        exit(1);
    }

    struct Funcionarios funcionario;
    int encontrado = 0;

    while (fscanf(arquivoFuncionarios, "ID do Funcionário: %d\n", &funcionario.funcionario_ID) == 1)
    {
        fscanf(arquivoFuncionarios, "Nome: %[^\n]\n", funcionario.nomeFuncionario);

        if (funcionario.funcionario_ID != funcionario_ID)
        {
            fprintf(arquivoTemp, "ID do Funcionário: %d\nNome: %s\n",
                    funcionario.funcionario_ID, funcionario.nomeFuncionario);
        }
        else
        {
            encontrado = 1;
        }
    }

    fclose(arquivoFuncionarios);
    fclose(arquivoTemp);

    if (encontrado)
    {
        if (remove("Funcionarios.txt") == 0)
        {
            if (rename("Temp.txt", "Funcionarios.txt") == 0)
            {
                printf("Funcionário deletado com sucesso.\n");
            }
            else
            {
                printf("Erro ao renomear arquivo.\n");
            }
        }
        else
        {
            printf("Erro ao remover o arquivo original.\n");
        }
    }
    else
    {
        remove("Temp.txt");
        printf("Funcionário não encontrado.\n");
    }
}

void deletarCliente(int cliente_ID)
{
    FILE *arquivoClientes = fopen("Clientes.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");

    if (arquivoClientes == NULL || arquivoTemp == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        system("Pause");
        exit(1);
    }

    struct Clientes cliente;
    int encontrado = 0;

    while (fscanf(arquivoClientes, "ID do Cliente: %d\n", &cliente.cliente_ID) == 1)
    {
        fscanf(arquivoClientes, "Nome: %[^\n]\n", cliente.nomeCliente);
        fscanf(arquivoClientes, "Endereço: %[^\n]\n", cliente.endereco);
        fscanf(arquivoClientes, "Tipo de Serviço: %[^\n]\n", cliente.tipoServico);

        if (cliente.cliente_ID != cliente_ID)
        {
            fprintf(arquivoTemp, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                    cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
        }
        else
        {
            encontrado = 1;
        }
    }

    fclose(arquivoClientes);
    fclose(arquivoTemp);

    if (encontrado)
    {
        if (remove("Clientes.txt") == 0)
        {
            if (rename("Temp.txt", "Clientes.txt") == 0)
            {
                printf("Cliente deletado com sucesso.\n");
            }
            else
            {
                printf("Erro ao renomear arquivo.\n");
            }
        }
        else
        {
            printf("Erro ao remover o arquivo original.\n");
        }
    }
    else
    {
        remove("Temp.txt");
        printf("Cliente não encontrado.\n");
    }
}


void editarVeiculo(int veiculo_ID)
{
    FILE *arquivoVeiculos = fopen("Veiculos.txt", "r");
    FILE *arquivoTemporario = fopen("Temporario.txt", "w");

    if (arquivoVeiculos == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        system("Pause");
        exit(1);
    }

    struct Veiculos veiculo;
    int encontrado = 0;

    while (fscanf(arquivoVeiculos, "ID do Veículo: %d\n", &veiculo.veiculo_ID) == 1)
    {
        fscanf(arquivoVeiculos, "Tipo: %[^\n]\n", veiculo.tipoVeiculo);
        fscanf(arquivoVeiculos, "Carga: %f Kg\n", &veiculo.cargaVeiculo);
        fscanf(arquivoVeiculos, "Status: %[^\n]\n", veiculo.statusVeiculo);

        if (veiculo.veiculo_ID == veiculo_ID)
        {
            encontrado = 1;

            char escolha_edit[10];
            printf("O que deseja editar? (Tipo/Carga/Status):\n");
            scanf("%9s", escolha_edit);

            if (strcmp(escolha_edit, "Tipo") == 0)
            {
                printf("Novo tipo de veículo: ");
                scanf(" %[^\n]", veiculo.tipoVeiculo);
            }
            else if (strcmp(escolha_edit, "Carga") == 0)
            {
                printf("Nova carga máxima (em kg): ");
                scanf("%f", &veiculo.cargaVeiculo);
            }
            else if (strcmp(escolha_edit, "Status") == 0)
            {
                printf("Status (disponível/ocupado): ");
                scanf(" %[^\n]", veiculo.statusVeiculo);
            }
            else
            {
                printf("Opção inválida! Nenhuma alteração realizada.\n");
            }
        }

        fprintf(arquivoTemporario, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
    }

    fclose(arquivoVeiculos);
    fclose(arquivoTemporario);

    if (encontrado)
    {
        if (remove("Veiculos.txt") == 0 && rename("Temporario.txt", "Veiculos.txt") == 0)
        {
            printf("Veículo editado com sucesso.\n");
        }
        else
        {
            printf("Erro ao atualizar os dados do veículo.\n");
        }
    }
    else
    {
        remove("Temporario.txt");
        printf("Veículo não encontrado.\n");
    }
}


void editarEntrega(int entrega_ID)
{
    FILE *arquivoEntregas = fopen("Entregas.txt", "r");
    FILE *arquivoTemporario = fopen("Temporario.txt", "w");

    if (arquivoEntregas == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        system("Pause");
        exit(1);
    }

    struct Entregas entrega;
    int encontrado = 0;

    while (fscanf(arquivoEntregas, "ID da Entrega: %d\n", &entrega.entrega_ID) == 1)
    {
        fscanf(arquivoEntregas, "Origem: %[^\n]\n", entrega.origem);
        fscanf(arquivoEntregas, "Destino: %[^\n]\n", entrega.destino);
        fscanf(arquivoEntregas, "Tempo Estimado: %f Horas\n", &entrega.tempoEstimado);

        if (entrega.entrega_ID == entrega_ID)
        {
            encontrado = 1;

            char escolha_edit[10];
            printf("O que deseja editar? (Origem/Destino/Tempo):\n");
            scanf("%9s", escolha_edit);

            if (strcmp(escolha_edit, "Origem") == 0)
            {
                printf("Nova origem: ");
                scanf(" %[^\n]", entrega.origem);
            }
            else if (strcmp(escolha_edit, "Destino") == 0)
            {
                printf("Novo destino: ");
                scanf(" %[^\n]", entrega.destino);
            }
            else if (strcmp(escolha_edit, "Tempo") == 0)
            {
                printf("Novo tempo estimado (em horas): ");
                scanf("%f", &entrega.tempoEstimado);
            }
            else
            {
                printf("Opção inválida! Nenhuma alteração realizada.\n");
            }
        }

        fprintf(arquivoTemporario, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
                entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
    }

    fclose(arquivoEntregas);
    fclose(arquivoTemporario);

    if (encontrado)
    {
        if (remove("Entregas.txt") == 0 && rename("Temporario.txt", "Entregas.txt") == 0)
        {
            printf("Entrega editada com sucesso.\n");
        }
        else
        {
            printf("Erro ao atualizar os dados da entrega.\n");
        }
    }
    else
    {
        remove("Temporario.txt");
        printf("Entrega não encontrada.\n");
    }
}


void editarFuncionario(int funcionario_ID)
{
    FILE *arquivoFuncionarios = fopen("Funcionarios.txt", "r");
    FILE *arquivoTemporario = fopen("Temporario.txt", "w");

    if (arquivoFuncionarios == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        system("Pause");
        exit(1);
    }

    struct Funcionarios funcionario;
    int encontrado = 0;

    while (fscanf(arquivoFuncionarios, "ID do Funcionário: %d\n", &funcionario.funcionario_ID) == 1)
    {
        fscanf(arquivoFuncionarios, "Nome: %[^\n]\n", funcionario.nomeFuncionario);

        if (funcionario.funcionario_ID == funcionario_ID)
        {
            encontrado = 1;

            printf("Novo nome do funcionário: ");
            scanf(" %[^\n]", funcionario.nomeFuncionario);
        }

        fprintf(arquivoTemporario, "ID do Funcionário: %d\nNome: %s\n",
                funcionario.funcionario_ID, funcionario.nomeFuncionario);
    }

    fclose(arquivoFuncionarios);
    fclose(arquivoTemporario);

    if (encontrado)
    {
        if (remove("Funcionarios.txt") == 0 && rename("Temporario.txt", "Funcionarios.txt") == 0)
        {
            printf("Funcionário editado com sucesso.\n");
        }
        else
        {
            printf("Erro ao atualizar os dados do funcionário.\n");
        }
    }
    else
    {
        remove("Temporario.txt");
        printf("Funcionário não encontrado.\n");
    }
}


void editarCliente(int cliente_ID)
{
    FILE *arquivoClientes = fopen("Clientes.txt", "r");
    FILE *arquivoTemporario = fopen("Temporario.txt", "w");

    if (arquivoClientes == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        system("Pause");
        exit(1);
    }

    struct Clientes cliente;
    int encontrado = 0;

    while (fscanf(arquivoClientes, "ID do Cliente: %d\n", &cliente.cliente_ID) == 1)
    {
        fscanf(arquivoClientes, "Nome: %[^\n]\n", cliente.nomeCliente);
        fscanf(arquivoClientes, "Endereço: %[^\n]\n", cliente.endereco);
        fscanf(arquivoClientes, "Tipo de Serviço: %[^\n]\n", cliente.tipoServico);

        if (cliente.cliente_ID == cliente_ID)
        {
            encontrado = 1;
            char escolha_edit[15];

            printf("O que deseja editar? (Nome/Endereco/Servico): ");
            scanf("%14s", escolha_edit);

            if (strcmp(escolha_edit, "Nome") == 0)
            {
                printf("Novo nome: ");
                scanf(" %[^\n]", cliente.nomeCliente);
            }
            else if (strcmp(escolha_edit, "Endereco") == 0)
            {
                printf("Novo endereço: ");
                scanf(" %[^\n]", cliente.endereco);
            }
            else if (strcmp(escolha_edit, "Servico") == 0)
            {
                printf("Novo tipo de serviço: ");
                scanf(" %[^\n]", cliente.tipoServico);
            }
            else
            {
                printf("Opção inválida.\n");
            }
        }

        fprintf(arquivoTemporario, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
    }

    fclose(arquivoClientes);
    fclose(arquivoTemporario);

    if (encontrado)
    {
        if (remove("Clientes.txt") == 0 && rename("Temporario.txt", "Clientes.txt") == 0)
        {
            printf("Cliente editado com sucesso.\n");
        }
        else
        {
            printf("Erro ao atualizar os dados do cliente.\n");
        }
    }
    else
    {
        remove("Temporario.txt");
        printf("Cliente não encontrado.\n");
    }
}


void visualizarVeiculoPorID(int veiculo_ID)
{
    FILE *arquivo = fopen("Veiculos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }

    struct Veiculos veiculo;
    int encontrado = 0;

    while (fscanf(arquivo, "ID do Veículo: %d\nTipo: %s\nCarga: %f Kg\nStatus: %s\n",
                  &veiculo.veiculo_ID, veiculo.tipoVeiculo, &veiculo.cargaVeiculo, veiculo.statusVeiculo) != EOF)
    {
        if (veiculo.veiculo_ID == veiculo_ID)
        {
            printf("ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                   veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
            encontrado = 1;
            break;
        }
    }
    fclose(arquivo);
    if (!encontrado)
    {
        printf("Veículo com ID %d não encontrado.\n", veiculo_ID);
    }
}

void visualizarEntregaPorID(int entrega_ID)
{
    FILE *arquivo = fopen("Entregas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de entregas.\n");
        return;
    }

    struct Entregas entrega;
    int encontrado = 0;

    while (fscanf(arquivo, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %f Horas\n",
                  &entrega.entrega_ID, entrega.origem, entrega.destino, &entrega.tempoEstimado) != EOF)
    {
        if (entrega.entrega_ID == entrega_ID)
        {
            printf("ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
                   entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
            encontrado = 1;
            break;
        }
    }
    fclose(arquivo);
    if (!encontrado)
    {
        printf("Entrega com ID %d não encontrada.\n", entrega_ID);
    }
}

void visualizarFuncionarioPorID(int funcionario_ID)
{
    FILE *arquivo = fopen("Funcionarios.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return;
    }

    struct Funcionarios funcionario;
    int encontrado = 0;

    while (fscanf(arquivo, "ID do Funcionário: %d\nNome: %s\n",
                  &funcionario.funcionario_ID, funcionario.nomeFuncionario) != EOF)
    {
        if (funcionario.funcionario_ID == funcionario_ID)
        {
            printf("ID do Funcionário: %d\nNome: %s\n",
                   funcionario.funcionario_ID, funcionario.nomeFuncionario);
            encontrado = 1;
            break;
        }
    }
    fclose(arquivo);
    if (!encontrado)
    {
        printf("Funcionário com ID %d não encontrado.\n", funcionario_ID);
    }
}

void visualizarClientePorID(int cliente_ID)
{
    FILE *arquivo = fopen("Clientes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    struct Clientes cliente;
    int encontrado = 0;

    while (fscanf(arquivo, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                  &cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico) != EOF)
    {
        if (cliente.cliente_ID == cliente_ID)
        {
            printf("ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                   cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
            encontrado = 1;
            break;
        }
    }
    fclose(arquivo);
    if (!encontrado)
    {
        printf("Cliente com ID %d não encontrado.\n", cliente_ID);
    }
}



void realizarEntrega() {
    int entrega_ID, funcionario_ID, veiculo_ID;
    float tempoRealizado;

    printf("Digite o ID da entrega que deseja realizar: ");
    scanf("%d", &entrega_ID);

    printf("Digite o ID do funcionário responsável: ");
    scanf("%d", &funcionario_ID);

    printf("Digite o ID do veículo utilizado: ");
    scanf("%d", &veiculo_ID);

    printf("Digite o tempo realizado (em horas): ");
    scanf("%f", &tempoRealizado);

    FILE *arquivoFuncionarios = fopen("Funcionarios.txt", "r");
    if (arquivoFuncionarios == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return;
    }

    int funcionarioEncontrado = 0;
    struct Funcionarios funcionario;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivoFuncionarios) != NULL) {
        if (sscanf(linha, "ID do Funcionário: %d", &funcionario.funcionario_ID) == 1) {
            if (funcionario.funcionario_ID == funcionario_ID) {
                funcionarioEncontrado = 1;
                fgets(linha, sizeof(linha), arquivoFuncionarios); 
                sscanf(linha, "Nome: %s", funcionario.nomeFuncionario);
                break;
            }
        }
    }
    fclose(arquivoFuncionarios);

    if (!funcionarioEncontrado) {
        printf("Funcionário com ID %d não encontrado.\n", funcionario_ID);
        return;
    }

    FILE *arquivoVeiculos = fopen("Veiculos.txt", "r");
    if (arquivoVeiculos == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }

    int veiculoEncontrado = 0;
    struct Veiculos veiculo;

    while (fgets(linha, sizeof(linha), arquivoVeiculos) != NULL) {
        if (sscanf(linha, "ID do Veículo: %d", &veiculo.veiculo_ID) == 1) {
            if (veiculo.veiculo_ID == veiculo_ID) {
                veiculoEncontrado = 1;
                fgets(linha, sizeof(linha), arquivoVeiculos); 
                sscanf(linha, "Tipo: %s", veiculo.tipoVeiculo);
                fgets(linha, sizeof(linha), arquivoVeiculos); 
                sscanf(linha, "Carga: %f Kg", &veiculo.cargaVeiculo);
                fgets(linha, sizeof(linha), arquivoVeiculos); 
                sscanf(linha, "Status: %s", veiculo.statusVeiculo);
                if (strcmp(veiculo.statusVeiculo, "disponivel") != 0) {
                    printf("Veículo com ID %d não está disponível.\n", veiculo_ID);
                    fclose(arquivoVeiculos);
                    return;
                }
                break;
            }
        }
    }
    fclose(arquivoVeiculos);

    if (!veiculoEncontrado) {
        printf("Veículo com ID %d não encontrado.\n", veiculo_ID);
        return;
    }

    FILE *arquivoEntregas = fopen("Entregas.txt", "r");
    if (arquivoEntregas == NULL) {
        printf("Erro ao abrir o arquivo de entregas.\n");
        return;
    }

    int entregaEncontrada = 0;
    struct Entregas entrega;

    while (fgets(linha, sizeof(linha), arquivoEntregas) != NULL) {
        if (sscanf(linha, "ID da Entrega: %d", &entrega.entrega_ID) == 1) {
            if (entrega.entrega_ID == entrega_ID) {
                entregaEncontrada = 1;
                fgets(linha, sizeof(linha), arquivoEntregas); 
                sscanf(linha, "Origem: %s", entrega.origem);
                fgets(linha, sizeof(linha), arquivoEntregas); 
                sscanf(linha, "Destino: %s", entrega.destino);
                fgets(linha, sizeof(linha), arquivoEntregas); 
                sscanf(linha, "Tempo Estimado: %f Horas", &entrega.tempoEstimado);
                break;
            }
        }
    }
    fclose(arquivoEntregas);

    if (!entregaEncontrada) {
        printf("Entrega com ID %d não encontrada.\n", entrega_ID);
        return;
    }

    int realizacao_ID = pegarUltimoId("idRealizacao.txt") + 1;
    atualizarId("idRealizacao.txt", realizacao_ID);


    FILE *arquivoRealizacoes = fopen("Realizacoes.txt", "a");
    if (arquivoRealizacoes == NULL) {
        printf("Erro ao abrir o arquivo de realizações.\n");
        return;
    }

    fprintf(arquivoRealizacoes, "Realização ID: %d\nEntrega ID: %d\nFuncionário ID: %d\nVeículo ID: %d\nTempo Realizado: %.1f Horas\n\n",
            realizacao_ID, entrega_ID, funcionario_ID, veiculo_ID, tempoRealizado);

    fclose(arquivoRealizacoes);

    FILE *arquivoVeiculosLeitura = fopen("Veiculos.txt", "r");
    FILE *arquivoVeiculosTemp = fopen("Temp.txt", "w");
    if (arquivoVeiculosLeitura == NULL || arquivoVeiculosTemp == NULL) {
        printf("Erro ao abrir arquivo de veículos.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivoVeiculosLeitura) != NULL) {
        if (sscanf(linha, "ID do Veículo: %d", &veiculo.veiculo_ID) == 1) {
            fgets(linha, sizeof(linha), arquivoVeiculosLeitura); 
            sscanf(linha, "Tipo: %s", veiculo.tipoVeiculo);
            fgets(linha, sizeof(linha), arquivoVeiculosLeitura);
            sscanf(linha, "Carga: %f Kg", &veiculo.cargaVeiculo);
            fgets(linha, sizeof(linha), arquivoVeiculosLeitura); 
            sscanf(linha, "Status: %s", veiculo.statusVeiculo);
            if (veiculo.veiculo_ID == veiculo_ID) {
                strcpy(veiculo.statusVeiculo, "ocupado");
            }
            fprintf(arquivoVeiculosTemp, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                    veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
        }
    }

    fclose(arquivoVeiculosLeitura);
    fclose(arquivoVeiculosTemp);

    remove("Veiculos.txt");
    rename("Temp.txt", "Veiculos.txt");

    printf("Entrega realizada com sucesso. ID da realização: %d\n", realizacao_ID);
}
int main()
{
    struct Veiculos veiculo;
    struct Entregas entrega;
    struct Funcionarios funcionario;
    struct Clientes cliente;

    char escolha1[12];
    char escolha2[13];

    int esc = 1;

    while (esc == 1)
    {
        printf("\nMENU\nO que deseja fazer?\n(Adicionar/Visualizar/Editar/Deletar/Realizar entrega/Relatorio)(sair)\n");
        scanf("%11s", escolha1);

        if (strcmp(escolha1, "Adicionar") == 0) // Tem q ser assim pra comparar string
        {
            esc = 2;
            while (esc == 2)
            {

                printf("\nO que deseja adicionar?\n(Veiculo/Entrega/Funcionario/Cliente)(voltar)\n");
                scanf("%12s", escolha2);
                if (strcmp(escolha2, "Veiculo") == 0)
                {
                    adicionarVeiculo(&veiculo);
                    cadastrarVeiculo(veiculo);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Entrega") == 0)
                {
                    adicionarEntrega(&entrega);
                    cadastrarEntrega(entrega);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Funcionario") == 0)
                {
                    adicionarFuncionario(&funcionario);
                    cadastrarFuncionario(funcionario);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Cliente") == 0)
                {
                    adicionarCliente(&cliente);
                    cadastrarCliente(cliente);
                    esc = 1;
                }
                else if (strcmp(escolha2, "voltar") == 0)
                {
                    esc = 1;
                }
                else
                {
                    printf("\nOps! Parece que houve um erro de digitacao \n");
                }
            }
        }
        else if (strcmp(escolha1, "Deletar") == 0)
        {
            esc = 2;
            while (esc == 2)
            {
                printf("\nO que deseja deletar?\n(Veiculo/Entrega/Funcionario/Cliente)(voltar)\n");
                scanf("%12s", escolha2);
                if (strcmp(escolha2, "Veiculo") == 0)
                {
                    int id;
                    printf("Digite o ID do veículo a ser deletado: ");
                    scanf("%d", &id);
                    deletarVeiculo(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Entrega") == 0)
                {
                    int id;
                    printf("Digite o ID da entrega a ser deletada: ");
                    scanf("%d", &id);
                    deletarEntrega(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Funcionario") == 0)
                {
                    int id;
                    printf("Digite o ID do funcionário a ser deletado: ");
                    scanf("%d", &id);
                    deletarFuncionario(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Cliente") == 0)
                {
                    int id;
                    printf("Digite o ID do cliente a ser deletado: ");
                    scanf("%d", &id);
                    deletarCliente(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "voltar") == 0)
                {
                    esc = 1;
                }
                else
                {
                    printf("\nOps! Parece que houve um erro de digitação.\n");
                }
            }
        }
        else if (strcmp(escolha1, "Editar") == 0)
        {
            esc = 2;
            while (esc == 2)
            {
                printf("\nO que deseja Editar? (Veiculo/Entrega/Funcionario/Cliente)(voltar)\n");
                scanf("%12s", escolha2);
                if (strcmp(escolha2, "Veiculo") == 0)
                {
                    int id;
                    printf("Digite o ID do veículo a ser editado: ");
                    scanf("%d", &id);
                    editarVeiculo(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Entrega") == 0)
                {
                    int id;
                    printf("Digite o ID da entrega a ser editado: ");
                    scanf("%d", &id);
                    editarEntrega(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Funcionario") == 0)
                {
                    int id;
                    printf("Digite o ID do funcionário a ser editado: ");
                    scanf("%d", &id);
                    editarFuncionario(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Cliente") == 0)
                {
                    int id;
                    printf("Digite o ID do cliente a ser editado: ");
                    scanf("%d", &id);
                    editarCliente(id);
                    esc = 1;
                }
                else if (strcmp(escolha2, "voltar") == 0)
                {
                    esc = 1;
                }
                else
                {
                    printf("\nOps! Parece que houve um erro de digitação.\n");
                }
            }
        }
        else if (strcmp(escolha1, "Visualizar") == 0)
        {
            esc = 2;
            while (esc == 2)
            {
                printf("\nO que deseja visualizar?\n(Veiculo/Entrega/Funcionario/Cliente)(voltar)\n");
                scanf("%12s", escolha2);

                if (strcmp(escolha2, "Veiculo") == 0)
                {
                    int idBuscado;
                    printf("Digite o ID que deseja visualizar: ");
                    scanf("%d", &idBuscado);
                    visualizarVeiculoPorID(idBuscado);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Entrega") == 0)
                {
                    int idBuscado;
                    printf("Digite o ID que deseja visualizar: ");
                    scanf("%d", &idBuscado);
                    visualizarEntregaPorID(idBuscado);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Funcionario") == 0)
                {
                    int idBuscado;
                    printf("Digite o ID que deseja visualizar: ");
                    scanf("%d", &idBuscado);
                    visualizarFuncionarioPorID(idBuscado);
                    esc = 1;
                }
                else if (strcmp(escolha2, "Cliente") == 0)
                {
                    int idBuscado;
                    printf("Digite o ID que deseja visualizar: ");
                    scanf("%d", &idBuscado);
                    visualizarClientePorID(idBuscado);
                    esc = 1;
                }
                else if (strcmp(escolha2, "voltar") == 0)
                {
                    esc = 1;
                }
                else
                {
                    printf("\nOps! Parece que houve um erro de digitação.\n");
                }
            }
        }
        else if (strcmp(escolha1,"Realizar entrega") == 0){
            realizarEntrega();
        }
        else if (strcmp(escolha1, "sair") == 0)
        {
            printf("\nSessão encerrada\n");
            esc = 0;
        }
        else
        {
            printf("\nOps! Parece que houve um erro de digitcao\n");
        }
    }
    return 0;
}
