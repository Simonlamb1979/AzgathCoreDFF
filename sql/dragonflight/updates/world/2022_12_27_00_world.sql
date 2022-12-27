-- quest_request_items_locale

INSERT IGNORE INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`) VALUES ('26222', 'frFR', 'Vous avez trouvé des pièces ?');
INSERT IGNORE INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`) VALUES ('26264', 'frFR', 'Vous avez pu récupérer les possessions des Gnomes irradiés ?');

-- quest_offer_reward_locale

INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('56775', 'frFR', 'Bien. Votre entraînement porte ses fruits, $c. De toute évidence, vous n’avez pas chômé au cours de la traversée.\r\n\r\nCe changement de temps aussi soudain qu’inattendu me préoccupe. Je vais en parler à l’équipage, voir de quoi il retourne. De votre côté, allez donc affronter le soldat Cole en combat amical.\r\n\r\nCela lui permettra de nous dire quel rôle vous réserver dans notre équipe sur le terrain.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('27670', 'frFR', 'Bien joué, $n. Mes hommes peuvent prendre le relais à partir d’ici. Maintenant, nous devons nous consacrer à l’évacuation des autres survivants.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('28167', 'frFR', 'C’est Nevin qui vous envoie ? Si c’est le cas, cela signifie qu’il se prépare à mettre un terme à cette mission. Le problème, c’est qu’il reste encore des survivants à secourir. Nous devons les aider !');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('27671', 'frFR', 'Je sais que Nevin sera ravi du nombre de survivants que vous avez réussi à évacuer. Je n’en reviens toujours pas que vous ayez conservé votre énergie malgré les radiations. Vous avez vu dans quel état sont les autres survivants ?\r\n\r\nJ’vous emmène à la salle de chargement pour qu’on vous décontamine.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('28169', 'frFR', 'C\'est un plaisir de vous rencontrer, $c. Les survivants font rarement preuve de votre force et de votre compétence. Je peux vous aider pour la procédure de décontamination, qui vous permettra de sortir d\'ici.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('27635', 'frFR', 'Et voilà. Vous êtes désormais paré pour remonter à la surface et commencer votre nouvelle vie. Le grand bricoleur sera enchanté de votre arrivée.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('27674', 'frFR', 'Ça fait plaisir de vous revoir, $n. Sans votre aide, nous n’aurions jamais pu évacuer autant de survivants de Gnomeregan. Tout le monde a vraiment hâte de vous rencontrer et d’entendre votre histoire.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26202', 'frFR', 'Tiens tiens, un autre survivant « secouru » par Nevin, hein ? C’est plutôt vous qui avez dû le sauver des Troggs, là en bas, n’est-ce pas ? Est-ce qu’il a bafouillé en prononçant mon nom ? Cet individu a une crainte respectueuse envers les forces que nous manipulons.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26424', 'frFR', 'Je suis ravi de faire votre connaissance, $n. Vous avez probablement entendu parler de l’opération Gnomeregan. Laissez-moi vous expliquer ce qui s’est passé et pourquoi nous avons quitté la ville de Forgefer.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26208', 'frFR', 'Même à l’heure actuelle, seules les équipes IMUN (Intervention Médicale d’Urgence Nationale) osent s’aventurer loin dans la ville afin de rechercher des survivants. Entre-temps, Thermojoncteur a envoyé l’un de ses lieutenants, Brisedent, pour nous distraire et lui permettre de se retrancher.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26566', 'frFR', 'Alors le Grand Bricoleur en personne a entendu parler de ma petite expérience ? Splendide ! J’ai presque terminé le dernier prototype, mais peut-être que vous pouvez m’aider à dénicher les pièces encore manquantes.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26222', 'frFR', 'Elles sont parfaites ! Maintenant, voyons voir ce qu’on peut en faire. Au fait, ça vous dirait de tester mon prototype, une fois qu’il sera fini ?');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26265', 'frFR', 'Quel soulagement ! Merci de votre aide. J’espère que le gadget sur lequel travaillait l’ingénieur Pulvétincelle pourra nous aider à décontaminer définitivement l’aérodrome.');
INSERT IGNORE INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES ('26264', 'frFR', 'J’ai hâte d’essayer cette nouvelle technologie ! Nous avons perdu un nombre incalculable de Gnomes à cause des radiations. Il est temps d’inverser la tendance !');

-- gameobject_template_locale

INSERT IGNORE INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`) VALUES ('203968', 'frFR', 'Pièce détachée', '', '18019');

-- creature_queststarter

DELETE FROM `creature_queststarter` WHERE  `id`=460 AND `quest`=26201;