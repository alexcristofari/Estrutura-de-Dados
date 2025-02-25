import random

def remover_pares(lista):
    lista[:] = [x for x in lista if x % 2 != 0]
    return len(lista)

lista = [random.randint(0, 99) for _ in range(10)]

print("Lista original:")
print(lista)

print("Tamanho original da lista:", len(lista))

novo_tamanho = remover_pares(lista)

print("Lista após remover pares:")
print(lista)

print("Tamanho da lista após remover pares:", novo_tamanho)
