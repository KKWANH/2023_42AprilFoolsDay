import requests
from termcolor import colored

def get_pokemon_abilities(pokemon_name):
    url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name.lower()}"
    response = requests.get(url)
    
    if response.status_code == 200:
        data = response.json()
        abilities = [ability["ability"]["name"] for ability in data["abilities"]]
        return abilities
    else:
        return None

def main():
    pokemon_name = input("Enter the name of a Pokemon: ")
    abilities = get_pokemon_abilities(pokemon_name)

    if abilities:
        print(colored(f"Name: {pokemon_name}", "green"))
        print(colored("Abilities:", "yellow"))
        for ability in abilities:
            print(colored(f"- {ability}", "cyan"))
    else:
        print(colored(f"Sorry, we couldn't find any information about {pokemon_name}.", "red"))

if __name__ == "__main__":
    main()
