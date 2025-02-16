#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVISO: Por favor, olhar as alterações dos colegas do grupo
// Caso tenha algo chato do C busque comentar ex: usar "strcmp" pra saber se strings são iguais

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
    scanf("%s", veiculo->tipoVeiculo);

    printf("Carga maxima (em kg): ");
    scanf("%f", &veiculo->cargaVeiculo);

    printf("Status (disponivel/ocupado): ");
    scanf("%s", veiculo->statusVeiculo);
    getchar();
}

void adicionarEntrega(struct Entregas *entrega)
{
    int id_entrega = pegarUltimoId("idEntrega.txt") + 1;
    atualizarId("idEntrega.txt", id_entrega);
    entrega->entrega_ID = id_entrega;

    printf("Origem: ");
    scanf("%s", entrega->origem);

    printf("Destino: ");
    scanf("%s", entrega->destino);

    printf("Tempo estimado (em horas): ");
    scanf("%f", &entrega->tempoEstimado);
    getchar();
}

void adicionarFuncionario(struct Funcionarios *funcionario)
{
    int id_funcionario = pegarUltimoId("idFuncionarios.txt") + 1;
    atualizarId("idFuncionarios.txt", id_funcionario);
    funcionario->funcionario_ID = id_funcionario;

    printf("Nome: ");
    scanf("%s", funcionario->nomeFuncionario);
    getchar();
}

void adicionarCliente(struct Clientes *cliente)
{
    int id_cliente = pegarUltimoId("idClientes.txt") + 1;
    atualizarId("idClientes.txt", id_cliente);
    cliente->cliente_ID = id_cliente;

    printf("Nome: ");
    scanf("%s", cliente->nomeCliente);

    printf("Endereco: ");
    scanf("%s", cliente->endereco);

    printf("Tipo de serviço: ");
    scanf("%s", cliente->tipoServico);
    getchar();
}
void deletarVeiculo(int veiculo_ID)
{
    FILE *arquivoVeiculos = fopen("Veiculos.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");
    if (arquivoVeiculos == NULL || arquivoTemp == NULL)
    {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Veiculos veiculo;
    int encontrado = 0;

    while (fscanf(arquivoVeiculos, "ID do Veículo: %d\nTipo: %s\nCarga: %f Kg\nStatus: %s\n",
                  &veiculo.veiculo_ID, veiculo.tipoVeiculo, &veiculo.cargaVeiculo, veiculo.statusVeiculo) != EOF)
    {
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
        remove("Veiculos.txt");
        rename("Temp.txt", "Veiculos.txt");
        printf("Veículo deletado com sucesso.\n");
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
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Entregas entrega;
    int encontrado = 0;

    while (fscanf(arquivoEntregas, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %f Horas\n",
                  &entrega.entrega_ID, entrega.origem, entrega.destino, &entrega.tempoEstimado) != EOF)
    {
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
        remove("Entregas.txt");
        rename("Temp.txt", "Entregas.txt");
        printf("Entrega deletada com sucesso.\n");
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
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Funcionarios funcionario;
    int encontrado = 0;

    while (fscanf(arquivoFuncionarios, "ID do Funcionário: %d\nNome: %s\n",
                  &funcionario.funcionario_ID, funcionario.nomeFuncionario) != EOF)
    {
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
        remove("Funcionarios.txt");
        rename("Temp.txt", "Funcionarios.txt");
        printf("Funcionário deletado com sucesso.\n");
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
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Clientes cliente;
    int encontrado = 0;

    while (fscanf(arquivoClientes, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                  &cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico) != EOF)
    {
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
        remove("Clientes.txt");
        rename("Temp.txt", "Clientes.txt");
        printf("Cliente deletado com sucesso.\n");
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
    if (arquivoVeiculos == NULL)
    {
        printf("Houve algum erro na abertura do arquivo veiculos");
        system("Pause");
        exit(1);
    }
    if (arquivoTemporario == NULL)
    {
        printf("Houve algum erro na abertura do arquivo temporario");
        system("Pause");
        exit(1);
    }

    struct Veiculos veiculo;
    int encontrado = 0;

    while (fscanf(arquivoVeiculos, "ID do Veículo: %d\nTipo: %s\nCarga: %f Kg\nStatus: %s\n",
                  &veiculo.veiculo_ID, veiculo.tipoVeiculo, &veiculo.cargaVeiculo, veiculo.statusVeiculo) != EOF)
    {
        if (veiculo.veiculo_ID != veiculo_ID)
        {
            fprintf(arquivoTemporario, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                    veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
        }

        else
        {

            veiculo.veiculo_ID = veiculo_ID;

            char escolha_edit[10];
            printf("O que deseja editar? (Tipo/Carga/Status):\n");
            scanf("%11s", escolha_edit);

            if (strcmp(escolha_edit, "Tipo") == 0)
            {
                printf("Novo tipo de veiculo: ");
                scanf("%s", veiculo.tipoVeiculo);
            }
            else if (strcmp(escolha_edit, "Carga") == 0)
            {
                printf("Nova carga maxima (em kg): ");
                scanf("%f", &veiculo.cargaVeiculo);
            }
            else if (strcmp(escolha_edit, "Status") == 0)
            {
                printf("Status (disponivel/ocupado): ");
                scanf("%s", veiculo.statusVeiculo);
            }
            else
            {
                printf("Ops! Parece que houve um erro de digitação.\n");
                break;
            }
            fprintf(arquivoTemporario, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                    veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
            encontrado = 1;
        }
    }
    fclose(arquivoVeiculos);
    fclose(arquivoTemporario);

    if (encontrado == 1)
    {
        remove("Veiculos.txt");
        rename("Temporario.txt", "Veiculos.txt");
        printf("Veículo editado com sucesso.\n");
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
    if (arquivoEntregas == NULL)
    {
        printf("Houve algum erro na abertura do arquivo entregas");
        system("Pause");
        exit(1);
    }
    if (arquivoTemporario == NULL)
    {
        printf("Houve algum erro na abertura do arquivo temporario");
        system("Pause");
        exit(1);
    }

    struct Entregas entrega;
    int encontrado = 0;

    while (fscanf(arquivoEntregas, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %f Horas\n",
                  &entrega.entrega_ID, entrega.origem, entrega.destino, &entrega.tempoEstimado) != EOF)
    {
        if (entrega.entrega_ID != entrega_ID)
        {
            fprintf(arquivoTemporario, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
                    entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
        }
        else
        {
            entrega.entrega_ID = entrega_ID;

            char escolha_edit[10];
            printf("O que deseja editar? (Origem/Destino/Tempo):\n");
            scanf("%11s", escolha_edit);

            if (strcmp(escolha_edit, "Origem") == 0)
            {
                printf("Nova origem: ");
                scanf("%s", entrega.origem);
            }
            else if (strcmp(escolha_edit, "Destino") == 0)
            {
                printf("Novo destino: ");
                scanf("%s", entrega.destino);
            }
            else if (strcmp(escolha_edit, "Tempo") == 0)
            {
                printf("Novo tempo estimado (em horas): ");
                scanf("%f", &entrega.tempoEstimado);
            }
            else
            {
                printf("Ops! Parece que houve um erro de digitação.\n");
                break;
            }
            fprintf(arquivoTemporario, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
                    entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
            encontrado = 1;
        }
    }
    fclose(arquivoEntregas);
    fclose(arquivoTemporario);

    if (encontrado == 1)
    {
        remove("Entregas.txt");
        rename("Temporario.txt", "Entregas.txt");
        printf("Entrega editada com sucesso.\n");
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
    if (arquivoFuncionarios == NULL)
    {
        printf("Houve algum erro na abertura do arquivo entregas");
        system("Pause");
        exit(1);
    }
    if (arquivoTemporario == NULL)
    {
        printf("Houve algum erro na abertura do arquivo temporario");
        system("Pause");
        exit(1);
    }

    struct Funcionarios funcionario;
    int encontrado = 0;

    while (fscanf(arquivoFuncionarios, "ID do Funcionário: %d\nNome: %s\n",
                  &funcionario.funcionario_ID, funcionario.nomeFuncionario) != EOF)
    {
        if (funcionario.funcionario_ID != funcionario_ID)
        {
            fprintf(arquivoTemporario, "ID do Funcionário: %d\nNome: %s\n",
                    funcionario.funcionario_ID, funcionario.nomeFuncionario);
        }
        else
        {
            funcionario.funcionario_ID = funcionario_ID;

            printf("Novo nome: ");
            scanf("%s", funcionario.nomeFuncionario);

            fprintf(arquivoTemporario, "ID do Funcionário: %d\nNome: %s\n",
                    funcionario.funcionario_ID, funcionario.nomeFuncionario);

            encontrado = 1;
        }
    }
    fclose(arquivoFuncionarios);
    fclose(arquivoTemporario);

    if (encontrado == 1)
    {
        remove("Funcionarios.txt");
        rename("Temporario.txt", "Funcionarios.txt");
        printf("Funcionario editado com sucesso.\n");
    }
    else
    {
        remove("Temporario.txt");
        printf("Funcionario não encontrada.\n");
    }
}

void editarCliente(int cliente_ID)
{
    FILE *arquivoClientes = fopen("Clientes.txt", "r");
    FILE *arquivoTemporario = fopen("Temporario.txt", "w");
    if (arquivoClientes == NULL)
    {
        printf("Houve algum erro na abertura do arquivo entregas");
        system("Pause");
        exit(1);
    }
    if (arquivoTemporario == NULL)
    {
        printf("Houve algum erro na abertura do arquivo temporario");
        system("Pause");
        exit(1);
    }

    struct Clientes cliente;
    int encontrado = 0;

    while (fscanf(arquivoClientes, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                  &cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico) != EOF)
    {
        if (cliente.cliente_ID != cliente_ID)
        {
            fprintf(arquivoTemporario, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                    cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
        }
        else
        {
            cliente.cliente_ID = cliente_ID;

            char escolha_edit[10];
            printf("O que deseja editar? (Nome/Endereco/Servico):\n");
            scanf("%11s", escolha_edit);

            if (strcmp(escolha_edit, "Nome") == 0)
            {
                printf("Novo nome: ");
                scanf("%s", cliente.nomeCliente);
            }
            else if (strcmp(escolha_edit, "Endereco") == 0)
            {
                printf("Novo endereco: ");
                scanf("%s", cliente.endereco);
            }
            else if (strcmp(escolha_edit, "Servico") == 0)
            {
                printf("Novo tipo de serviço: ");
                scanf("%s", cliente.tipoServico);
            }
            else
            {
                printf("Ops! Parece que houve um erro de digitação.\n");
                break;
            }
            fprintf(arquivoTemporario, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                    cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
            encontrado = 1;
        }
    }
    fclose(arquivoClientes);
    fclose(arquivoTemporario);

    if (encontrado == 1)
    {
        remove("Clientes.txt");
        rename("Temporario.txt", "Clientes.txt");
        printf("Cliente editado com sucesso.\n");
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
        printf("\nMENU\nO que deseja fazer?\n(Adicionar/Visualizar/Editar/Deletar/Realizar entrega)(sair)\n");
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
