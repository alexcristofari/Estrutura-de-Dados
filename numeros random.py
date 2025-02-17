import random

n = random.randint(10, 20)

lista_original = list(set(random.randint(1, 100) for _ in range(n)))

lista_par = [num for num in lista_original if num % 2 == 0]
lista_impar = [num for num in lista_original if num % 2 != 0]

print(f"\n Quantidade de numeros gerados: {len(lista_original)}")
print(f"\n Quantidade de numeros pares: {sorted(lista_par)}")
print(f"\n Quantidade de numeors impares: {sorted(lista_impar)}")
print(f"\n Lista Original: {sorted(lista_original)}")


