# ESP32_coleta
O código possui a maior velocidade de coleta que eu consegui atingir utilizando um esp32.
O modelo foi NodeMCU 32s e os dados eram enviados em 12 bits através de ADC9226.
O código lê o estado de todos os pinos de um esp32 e salva em um vetor, 5000 pontos, a uma velocidade 1.356 MHz
A única parte que importa na coleta é ciclo do for

for(int i = 0; i<COLETA; i++){
                REG_WRITE(GPIO_OUT_W1TS_REG, BIT5);//GPIO2 HIGH (set)
                REG_WRITE(GPIO_OUT_W1TC_REG, BIT5);//GPIO2 LOW (clear)
                data_aq[i] = (GPIO_IN_REG) & PIN_MASK;
            }

Foi utilizado a escrita nos registradores para melhorar a velocidade do clock e a leitura em paralelo de todos os pinos.
Não sei se existe um ciclo de loop mais rápido que o for, se tiver pode melhorar o desempenho do código.

Foram feitos alguns outros testes para testar a velocidade do ESP32:
  Se ao invés de um vetor fosse apenas em uma variável a velocidade é de 2.962 MHz
  Executando a função de leitura, mas sem escrever os dados em nenhuma variável a velocidade é de 3.479 MHz 
  Sem ler e escrever apenas gerando um sinal de clock a velocidade é de 7.278 MHz
