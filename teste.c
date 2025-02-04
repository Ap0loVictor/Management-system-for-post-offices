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


int main()
{
    struct Veiculos veiculo;
    struct Entregas entrega;
    struct Funcionarios funcionario;
    struct Clientes cliente;

    int idVeiculo = 0, idEntrega = 0, idFuncionario = 0, idCliente = 0;
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
            idFuncionario +=1;
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
    else
    {
        printf("Ops! Parece que houve um erro de digitcao");
    }

    return 0;
}
