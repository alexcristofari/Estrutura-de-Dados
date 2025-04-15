using System;
using System.Collections.Generic;

class ProcessadorDeFilas {
    static void Main(string[] args) {
        Queue<string> filaUrgente = new Queue<string>();
        Queue<string> filaNormal = new Queue<string>();

        Random random = new Random();
        int idNormal = 0;
        int idUrgente = 100;

        for (int i = 0; i < 50; i++) {
            int numeroProcesso = random.Next(0, 200);
            string processoAtendido;

            if (numeroProcesso == 0) {
                if (filaUrgente.Count > 0) {
                    processoAtendido = filaUrgente.Dequeue();
                    Console.WriteLine("Processo urgente atendido: " + processoAtendido);
                } else {
                    Console.WriteLine("Nenhum processo urgente para atender.");
                }
            } else if (numeroProcesso == 100) {
                if (filaNormal.Count > 0) {
                    processoAtendido = filaNormal.Dequeue();
                    Console.WriteLine("Processo normal atendido: " + processoAtendido);
                } else {
                    Console.WriteLine("Nenhum processo normal para atender.");
                }
            } else if (numeroProcesso >= 0 && numeroProcesso <= 99) {
                string processo = "URG" + idUrgente;
                idUrgente++;
                filaUrgente.Enqueue(processo);
                Console.WriteLine("Inserido processo urgente: " + processo);
            } else if (numeroProcesso >= 100 && numeroProcesso <= 199) {
                string processo = "NOR" + idNormal;
                idNormal++;
                filaNormal.Enqueue(processo);
                Console.WriteLine("Inserido processo normal: " + processo);
            }
        }

        Console.WriteLine();
        Console.WriteLine("Fila urgente restante:");
        foreach (var p in filaUrgente) {
            Console.WriteLine(p);
        }

        Console.WriteLine();
        Console.WriteLine("Fila normal restante:");
        foreach (var p in filaNormal) {
            Console.WriteLine(p);
        }
    }
}
