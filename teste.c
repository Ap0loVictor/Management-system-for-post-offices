#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
//\n

// Teste de commit pra ver como funciona
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

    struct veiculos {
        int veiculoID; // numerico ou igual placa de carro??
        char tipo_veiculo[20]; // moto, caminhão, carro, etc...
        float carga_veiculo; // em KG    
        char status_veiculo[10]; // disponível ou ocupado
    };
    
    struct entregas {
        int entregaID;
        char origem[100]; // endereço
        char destino[100]; // endereco
        float tempo; // Em horas
    };
    
    struct funcionarios {
        int funcionarioID;
        char nome_funcionario[50];
    };
    
    struct clientes {
        int clienteID;
        char nome_cliente[50];
        char endereco[100];
        char tipo_servico[20];
    };
    
    void info_veiculo (struct veiculos veiculo) {
        FILE *fv = fopen("Veiculos.txt","a");
        if (fv == NULL) {
            printf("Erro ao abrir arquivo.");
            system("Pause");
            exit(1);
        }
            fprintf(fv, "ID do Veículo: %d\nTipo veiculo: %s\nCarga veiculo: %.2f Kg\nStatus veiculo: %s\n", veiculo.veiculoID, veiculo.tipo_veiculo, veiculo.carga_veiculo, veiculo.status_veiculo);
            fclose(fv);
            printf("\nAs informações do veículo estão salvas no sistema!\n");
    }
    
    void Dados_Veiculo(struct veiculos *veiculo) {
    printf("Informe os dados do veículo:\n\n");
    printf("ID do Veículo: ");
    scanf("%d", &veiculo->veiculoID);

    printf("Tipo de veículo: ");
    scanf("%s", veiculo->tipo_veiculo);

    printf("Carga que o veículo carrega (em kg): ");
    scanf("%f", &veiculo->carga_veiculo);

    printf("Status do veículo (disponível/ocupado): ");
    scanf("%s", veiculo->status_veiculo);
}

    void info_entrega (struct entregas entrega) {
        FILE *fe = fopen("Entregas.txt","a"); 
        if (fe == NULL) {
            printf("Erro ao abrir arquivo.");
            system("Pause");
            exit(1);    
        }
        fprintf(fe, "ID da Entrega: %d\nOrigem da Entrega: %s\nDestino da Entrega: %s\nTempo Estimado: %.1f Horas\n", entrega.entregaID, entrega.origem, entrega.destino, entrega.tempo);
            fclose(fe);
            printf("\nAs informações da entrega estão salvas no sistema!\n");
    }
    
    void Dados_Entrega (struct entregas *entrega) {
    printf("\nInforme os dados da entrega:\n");
    printf("ID da entrega: ");
    scanf("%d", &entrega->entregaID);

    printf("Origem da entrega: ");
    scanf("%s", entrega->origem);

    printf("Destino da entrega: ");
    scanf("%s", entrega->destino);

    printf("Tempo estimado (em horas): ");
    scanf("%f", &entrega->tempo);
    }
    
    void info_funcionarios (struct funcionarios funcionario) {
        FILE *ff = fopen("Funcionarios.txt","a"); 
        if (ff == NULL) {
            printf("Erro ao abrir arquivo.");
            system("Pause");
            exit(1);    
        }
        fprintf(ff, "ID do funcionario: %d\nNome do funcionario: %s\n", funcionario.funcionarioID , funcionario.nome_funcionario);
            fclose(ff);
            printf("\nAs informações do funcionario estão salvas no sistema!\n");
    }
    
    void dados_funcionarios (struct funcionarios *funcionario) {
        printf("\nInforme os dados do funcionario:\n");
        printf("ID do funcionario: \n");
        scanf("%d", &funcionario->funcionarioID);

        printf("Nome do funcionario: \n");
        scanf("%s", funcionario->nome_funcionario);
    }
    
    void info_clientes(struct clientes cliente) {
    FILE *fc = fopen("Clientes.txt", "a"); 
    if (fc == NULL) {
        printf("Erro ao abrir arquivo.");
        system("Pause");
        exit(1);    
    }
    fprintf(fc, "ID do cliente: %d\nNome do cliente: %s\nEndereco: %s\nTipo de servico: %s\n", 
            cliente.clienteID, cliente.nome_cliente, cliente.endereco, cliente.tipo_servico);
    fclose(fc);
    printf("\nAs informacoes do cliente estao salvas no sistema!\n");
}

void dados_clientes(struct clientes *cliente) {
    printf("\nInforme os dados do cliente:\n");
    printf("ID do cliente: \n");
    scanf("%d", &cliente->clienteID);

    printf("Nome do cliente: \n");
    scanf("%s", cliente->nome_cliente);
    
    printf("Endereco: \n");
    scanf("%s", cliente->endereco);
    
    printf("Tipo de servico: \n");
    scanf("%s", cliente->tipo_servico);
}

    
    
int main() {
    struct veiculos veiculo;
    struct entregas entrega;
    struct funcionarios funcionario;
    struct clientes cliente;
    
    Dados_Veiculo(&veiculo);
    info_veiculo(veiculo);
    
    Dados_Entrega(&entrega);
    info_entrega(entrega);
    
    dados_funcionarios(&funcionario);
    info_funcionarios(funcionario);
    
    dados_clientes(&cliente);
    info_clientes(cliente);
    return 0; 
}