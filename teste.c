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

void infoVeiculo(struct Veiculos veiculo)
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
    printf("\nAs informações do veículo foram salvas no sistema!\n");
}

void dadosVeiculo(struct Veiculos *veiculo)
{
    printf("Informe os dados do veículo:\n\n");
    printf("ID do Veículo: ");
    scanf("%d", &veiculo->veiculo_ID);

    printf("Tipo de veículo: ");
    scanf("%s", veiculo->tipoVeiculo);

    printf("Carga máxima (em kg): ");
    scanf("%f", &veiculo->cargaVeiculo);

    printf("Status (disponível/ocupado): ");
    scanf("%s", veiculo->statusVeiculo);
}

void infoEntrega(struct Entregas entrega)
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
    printf("\nAs informações da entrega foram salvas no sistema!\n");
}

void dadosEntrega(struct Entregas *entrega)
{
    printf("\nInforme os dados da entrega:\n");
    printf("ID da entrega: ");
    scanf("%d", &entrega->entrega_ID);

    printf("Origem: ");
    scanf("%s", entrega->origem);

    printf("Destino: ");
    scanf("%s", entrega->destino);

    printf("Tempo estimado (em horas): ");
    scanf("%f", &entrega->tempoEstimado);
}

void infoFuncionario(struct Funcionarios funcionario)
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
    printf("\nAs informações do funcionário foram salvas no sistema!\n");
}

void dadosFuncionario(struct Funcionarios *funcionario)
{
    printf("\nInforme os dados do funcionário:\n");
    printf("ID do funcionário: ");
    scanf("%d", &funcionario->funcionario_ID);

    printf("Nome: ");
    scanf("%s", funcionario->nomeFuncionario);
}

void infoCliente(struct Clientes cliente)
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
    printf("\nAs informações do cliente foram salvas no sistema!\n");
}

void dadosCliente(struct Clientes *cliente)
{
    printf("\nInforme os dados do cliente:\n");
    printf("ID do cliente: ");
    scanf("%d", &cliente->cliente_ID);

    printf("Nome: ");
    scanf("%s", cliente->nomeCliente);

    printf("Endereço: ");
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

    dadosVeiculo(&veiculo);
    infoVeiculo(veiculo);

    dadosEntrega(&entrega);
    infoEntrega(entrega);

    dadosFuncionario(&funcionario);
    infoFuncionario(funcionario);

    dadosCliente(&cliente);
    infoCliente(cliente);

    return 0;
}
