# Définitions Générales
TARGETS=
CFLAGS=-g -W -Wall -Werror
LFLAGS=-g -W -Wall -Werror

define SRC_2_OBJ
  $(foreach src,$(1),$(patsubst src/%.s,build/%.o,\
		$(patsubst src/%.c,build/%.o,$(src))))
endef

all: targets

# Règles génériques

out/%:
	mkdir -p $(dir $@)
	gcc -o $@ $(LFLAGS) $^

build/%.o: src/%.s
	mkdir -p $(dir $@)
	gcc -c -o $@ $(CFLAGS) $<

build/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc -c -o $@ $(CFLAGS) $<

# Règles spécifiques

# Définition de programme q0
# Ajout des dépendances au programme q0 : fichiers src/q0/q0.c et src/q0/as.s
out/q0: $(call SRC_2_OBJ, src/q0/q0.c) $(call SRC_2_OBJ, src/q0/as.s)
# Ajout de l'exécutable que l'ont veut génerer : out/q0
TARGETS+=out/q0

# Définition de programme q1
out/q1: $(call SRC_2_OBJ, src/q1/bs.c) $(call SRC_2_OBJ, src/q1/q1.s)
TARGETS+=out/q1

# Définition de programme q2
out/q2: $(call SRC_2_OBJ, src/q2/q2.c)
TARGETS+=out/q2

# Définition de programme q3
out/q3: $(call SRC_2_OBJ, src/q3/q3.c)
TARGETS+=out/q3

# Définition de programme q4
out/q4: $(call SRC_2_OBJ, src/q4/q4.c)
TARGETS+=out/q4

# Définition de programme q5
out/q5: $(call SRC_2_OBJ, src/q5/q5.c)
TARGETS+=out/q5

# Règles pratiques
targets: $(TARGETS)

info:
	@echo $(TARGETS)

clean:
	rm -fr out build
