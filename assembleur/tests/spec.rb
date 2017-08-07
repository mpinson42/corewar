
TMP_DIR             = 'tmp_compiled_champs'

# Liste des champions à compiler (ils se treouvent dans le dossier 'champs_for_spec')
# arguments:
#   - nom du fichier du champion
#   - description du test
#   - flag pour activer / désactiver le test

all_champs = [
  ["42"                 ,         false], # Champ_max_size
  ["Backward"           ,         false], # Commande invalide `.extend`
  ["Car"                , true],
  ["Death"              ,         false], # Commande invalide `.extend`
  ["Gagnant"            , true],
  ["Octobre_Rouge_V4.2" , true],
  ["Survivor"           ,         false], # Lignes wtf
  ["Torpille"           ,         false], # Commande invalide `.extend`
  ["barriere"           ,         false], # Champ_max_size
  ["ex"                 , true],
  ["jumper"             , true],
  ["lde"                ,         false], # Champ_max_size
  ["leeloo"             ,         false], # Ligne mal formatée
  ["mat"                ,         false], # Ligne mal formatée
  ["maxidef"            , true],
  ["mortel"             , true],
  ["new"                ,         false], # Commande invalide `.extend`
  ["sebc"               ,         false], # Commande invalide `.extend`
  ["slider2"            , true],
  ["tdc2"               ,         false], # Commande invalide `.extend`
  ["tdc3"               ,         false], # Commande invalide `.extend`
  ["tdc4"               ,         false], # Commande invalide `.extend`
  ["test"               ,         false], # Valeur de .name trop longue
  ["toto"               , true]
]
champs_to_test = all_champs.select { |c| c[1] == true }

#

def get_champ_from_resources(c)
  `cp ../../resources/champions/#{c}.s #{TMP_DIR}/#{c}_ref.s`
  `cp ../../resources/champions/#{c}.s #{TMP_DIR}/#{c}.s`
end

def compile_champ(c)
  `./asm_ref #{TMP_DIR}/#{c}_ref.s`
  `./asm #{TMP_DIR}/#{c}.s`
end

def hexdump_asm(c)
  `hexdump -vC #{TMP_DIR}/#{c}.cor`
end

def hexdump_asm_ref(c)
  `hexdump -vC #{TMP_DIR}/#{c}_ref.cor`
end

#

describe 'Tests de l\'ASM' do
  before(:all) do
    `mkdir -p #{TMP_DIR}`
    `cp ../../resources/asm_ref .`
    `chmod +x asm_ref`
    `make -C ../project`
    `cp ../project/asm .`
    `chmod +x asm`
    all_champs.each do |champ_line|
      get_champ_from_resources(champ_line[0])
    end
  end

  champs_to_test.each do |champ_line|
    it "doit rendre le même binaire que asm_ref pour '#{champ_line[0]}.s'" do
      champ = champ_line[0]

      compile_champ(champ)
      hex_out     = hexdump_asm(champ)
      hex_out_ref = hexdump_asm_ref(champ)

      expect(hex_out).not_to be_empty
      expect(hex_out_ref).not_to be_empty
      expect(hex_out).to eq(hex_out_ref)
    end
  end
end
