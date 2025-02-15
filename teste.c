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

int pegarUltimoId(const char *arquivoDaEntidade){
    FILE *arquivoId = fopen(arquivoDaEntidade, "r");
    if (arquivoId == NULL){
        arquivoId = fopen(arquivoDaEntidade,"w");
        if (arquivoId == NULL){
            printf("Erro ao criar o arquivo");
            system("Pause");
            exit(1);
        }
        fprintf(arquivoId,"0");
        fclose(arquivoId);
        return 0;
    }
    int ultimo_id;
    fscanf(arquivoId,"%d",&ultimo_id);
    fclose(arquivoId);
    return ultimo_id;
}
void atualizarId(const char *arquivoDaEntidade, int novo_id){
    FILE *arquivoId = fopen(arquivoDaEntidade, "w");
    if (arquivoId == NULL){
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
    int id_veiculo = pegarUltimoId("IdVeiculo.txt")+1;
    atualizarId("idVeiculo.txt",id_veiculo);
    veiculo->veiculo_ID = id_veiculo;

    printf("Tipo de veiculo: ");
    scanf("%s", veiculo->tipoVeiculo);

    printf("Carga maxima (em kg): ");
    scanf("%f", &veiculo->cargaVeiculo);

    printf("Status (disponivel/ocupado): ");
    scanf("%s", veiculo->statusVeiculo);
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
}

void adicionarFuncionario(struct Funcionarios *funcionario)
{
    int id_funcionario = pegarUltimoId("idFuncionarios.txt")+1;
    atualizarId("idFuncionarios.txt", id_funcionario);
    funcionario->funcionario_ID = id_funcionario;

    printf("Nome: ");
    scanf("%s", funcionario->nomeFuncionario);
}

void adicionarCliente(struct Clientes *cliente)
{
    int id_cliente = pegarUltimoId("idClientes.txt")+1;
    atualizarId("idClientes.txt", id_cliente);
    cliente->cliente_ID = id_cliente;

    printf("Nome: ");
    scanf("%s", cliente->nomeCliente);

    printf("Endereco: ");
    scanf("%s", cliente->endereco);

    printf("Tipo de serviço: ");
    scanf("%s", cliente->tipoServico);
}
void deletarVeiculo(int veiculo_ID) {
    FILE *arquivoVeiculos = fopen("Veiculos.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");
    if (arquivoVeiculos == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Veiculos veiculo;
    int encontrado = 0;

    while (fscanf(arquivoVeiculos, "ID do Veículo: %d\nTipo: %s\nCarga: %f Kg\nStatus: %s\n",
                 &veiculo.veiculo_ID, veiculo.tipoVeiculo, &veiculo.cargaVeiculo, veiculo.statusVeiculo) != EOF) {
        if (veiculo.veiculo_ID != veiculo_ID) {
            fprintf(arquivoTemp, "ID do Veículo: %d\nTipo: %s\nCarga: %.2f Kg\nStatus: %s\n",
                    veiculo.veiculo_ID, veiculo.tipoVeiculo, veiculo.cargaVeiculo, veiculo.statusVeiculo);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivoVeiculos);
    fclose(arquivoTemp);

    if (encontrado) {
        remove("Veiculos.txt");
        rename("Temp.txt", "Veiculos.txt");
        printf("Veículo deletado com sucesso.\n");
    } else {
        remove("Temp.txt");
        printf("Veículo não encontrado.\n");
    }
}

void deletarEntrega(int entrega_ID) {
    FILE *arquivoEntregas = fopen("Entregas.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");
    if (arquivoEntregas == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Entregas entrega;
    int encontrado = 0;

    while (fscanf(arquivoEntregas, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %f Horas\n",
                  &entrega.entrega_ID, entrega.origem, entrega.destino, &entrega.tempoEstimado) != EOF) {
        if (entrega.entrega_ID != entrega_ID) {
            fprintf(arquivoTemp, "ID da Entrega: %d\nOrigem: %s\nDestino: %s\nTempo Estimado: %.1f Horas\n",
                    entrega.entrega_ID, entrega.origem, entrega.destino, entrega.tempoEstimado);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivoEntregas);
    fclose(arquivoTemp);

    if (encontrado) {
        remove("Entregas.txt");
        rename("Temp.txt", "Entregas.txt");
        printf("Entrega deletada com sucesso.\n");
    } else {
        remove("Temp.txt");
        printf("Entrega não encontrada.\n");
    }
}
void deletarFuncionario(int funcionario_ID) {
    FILE *arquivoFuncionarios = fopen("Funcionarios.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");
    if (arquivoFuncionarios == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Funcionarios funcionario;
    int encontrado = 0;

    while (fscanf(arquivoFuncionarios, "ID do Funcionário: %d\nNome: %s\n",
                  &funcionario.funcionario_ID, funcionario.nomeFuncionario) != EOF) {
        if (funcionario.funcionario_ID != funcionario_ID) {
            fprintf(arquivoTemp, "ID do Funcionário: %d\nNome: %s\n",
                    funcionario.funcionario_ID, funcionario.nomeFuncionario);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivoFuncionarios);
    fclose(arquivoTemp);

    if (encontrado) {
        remove("Funcionarios.txt");
        rename("Temp.txt", "Funcionarios.txt");
        printf("Funcionário deletado com sucesso.\n");
    } else {
        remove("Temp.txt");
        printf("Funcionário não encontrado.\n");
    }
}
void deletarCliente(int cliente_ID) {
    FILE *arquivoClientes = fopen("Clientes.txt", "r");
    FILE *arquivoTemp = fopen("Temp.txt", "w");
    if (arquivoClientes == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);
    }

    struct Clientes cliente;
    int encontrado = 0;

    while (fscanf(arquivoClientes, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                  &cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico) != EOF) {
        if (cliente.cliente_ID != cliente_ID) {
            fprintf(arquivoTemp, "ID do Cliente: %d\nNome: %s\nEndereço: %s\nTipo de Serviço: %s\n",
                    cliente.cliente_ID, cliente.nomeCliente, cliente.endereco, cliente.tipoServico);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivoClientes);
    fclose(arquivoTemp);

    if (encontrado) {
        remove("Clientes.txt");
        rename("Temp.txt", "Clientes.txt");
        printf("Cliente deletado com sucesso.\n");
    } else {
        remove("Temp.txt");
        printf("Cliente não encontrado.\n");
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
    printf("O que deseja fazer? (Adicionar/Visualizar/Editar/Deletar)\n");
    scanf("%11s", escolha1);

    if (strcmp(escolha1, "Adicionar") == 0) //Tem q ser assim pra comparar string
    {
        printf("O que deseja adicionar? (Veiculo/Entrega/Funcionario/Cliente)\n");
        scanf("%12s", escolha2);
        if (strcmp(escolha2, "Veiculo") == 0)
        {
            adicionarVeiculo(&veiculo);
            cadastrarVeiculo(veiculo);
        }
        else if (strcmp(escolha2, "Entrega") == 0)
        {
            adicionarEntrega(&entrega);
            cadastrarEntrega(entrega);
        }
        else if (strcmp(escolha2, "Funcionario") == 0)
        {
            adicionarFuncionario(&funcionario);
            cadastrarFuncionario(funcionario);
        }
        else if (strcmp(escolha2, "Cliente") == 0)
        {
            adicionarCliente(&cliente);
            cadastrarCliente(cliente);
        }
        else
        {
            printf("Ops! Parece que houve um erro de digitacao");
        }
    }
    else if (strcmp(escolha1, "Deletar") == 0) 
    {
        printf("O que deseja deletar? (Veiculo/Entrega/Funcionario/Cliente)\n");
        scanf("%12s", escolha2);
        if (strcmp(escolha2, "Veiculo") == 0) {
            int id;
            printf("Digite o ID do veículo a ser deletado: ");
            scanf("%d", &id);
            deletarVeiculo(id);
        } else if (strcmp(escolha2, "Entrega") == 0) {
            int id;
            printf("Digite o ID da entrega a ser deletada: ");
            scanf("%d", &id);
            deletarEntrega(id);
        } else if (strcmp(escolha2, "Funcionario") == 0) {
            int id;
            printf("Digite o ID do funcionário a ser deletado: ");
            scanf("%d", &id);
            deletarFuncionario(id);
        } else if (strcmp(escolha2, "Cliente") == 0) {
            int id;
            printf("Digite o ID do cliente a ser deletado: ");
            scanf("%d", &id);
            deletarCliente(id);
        } else {
            printf("Ops! Parece que houve um erro de digitação.\n");
        }
    }
    else
    {
        printf("Ops! Parece que houve um erro de digitcao");
    }






    return 0;
}
