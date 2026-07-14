#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Vamos modificar o MenuLayer, que é a tela inicial do jogo
class $modify(MyModPackMenu, MenuLayer) {
    
    bool init() {
        // Sempre chame a função original primeiro para carregar o menu normal
        if (!MenuLayer::init()) {
            return false;
        }

        // Puxa o valor salvo para checar se o popup já apareceu. 
        // O "false" no final é o valor padrão (caso seja a primeira vez abrindo).
        bool hasShownPopup = Mod::get()->getSavedValue<bool>("welcome-popup-shown", false);

        if (!hasShownPopup) {
            // Cria o Pop Up. 
            // Dica: <cy> deixa o texto amarelo (cyan) e <c> fecha a cor.
            FLAlertLayer::create(
                "ModPack Installed!", 
				"Click OK to ignore this.", 
                "OK"
            )->show();

            // Salva no sistema do Geode que o popup já foi mostrado.
            // Assim, na próxima vez que abrir o jogo, a variável 'hasShownPopup' será true.
            Mod::get()->setSavedValue("welcome-popup-shown", true);
        }

        return true;
    }
};
