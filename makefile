# Variables
CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
DATA_DIR = data

# Fichiers sources et objets
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXEC = $(BUILD_DIR)/main.exe

# Règle principale
all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJ_FILES) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)

# Réinitialisation complète (nettoyage et suppression des fichiers générés)
reset: clean
	rm -rf $(BUILD_DIR)

# Règle par défaut
.DEFAULT_GOAL := all
