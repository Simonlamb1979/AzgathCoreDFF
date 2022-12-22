-- playercreateinfo_action

INSERT INTO playercreateinfo_action (race, class, button, action, type) VALUES
(52, 13, 0, 131347, 0),
(52, 13, 1, 368970, 0),
(52, 13, 2, 357214, 0),
(52, 13, 3, 362969, 0),
(52, 13, 4, 361469, 0),
(52, 13, 5, 351624, 0);

-- playercreateinfo

DELETE FROM playercreateinfo WHERE class=13;
INSERT INTO playercreateinfo (race, class, map, position_x, position_y, position_z, orientation, npe_map, npe_position_x, npe_position_y, npe_position_z, npe_orientation, npe_transport_guid, intro_movie_id, intro_scene_id, npe_intro_scene_id) VALUES 
(52, 13, 2570, 5827.53, -2982.55, 251.047, 3.86788, NULL, NULL, NULL, NULL, NULL, NULL, 969, 0, NULL),
(70, 13, 2570, 5827.53, -2982.55, 251.047, 3.86788, NULL, NULL, NULL, NULL, NULL, NULL, 969, 0, NULL);