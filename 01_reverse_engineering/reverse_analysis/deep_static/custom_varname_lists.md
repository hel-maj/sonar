# Custom varname/local lists

Nuitka leaves many function local-variable tuples as constants. The exact function binding still needs confirmation in the native decompiler, but these lists expose internal variables and workflow steps.

## __main__
- `236` (1): `__class__`
- `237` (6): `self, app_id, e, icon_path, icon, config_dir`
- `238` (3): `self, is_valid, message`
- `241` (3): `self, reason, activated`
- `244` (4): `self, reason, fishing_tab, fishing_bot`
- `246` (4): `self, exit_code, e, msg_box`
- `247` (13): `self, reason, telegram_settings, enabled, bot_token, chat_id, admin_ids_str, requests, message, url, payload, response, e`
- `248` (5): `self, expired_message, msg_box, dialog, result`

## __parents_main__
- `243` (1): `__class__`
- `244` (6): `self, app_id, e, icon_path, icon, config_dir`
- `245` (8): `sys, builtins, multiprocessing, kwds, args, arg, name, value`
- `246` (3): `self, is_valid, message`
- `249` (3): `self, reason, activated`
- `252` (4): `self, reason, fishing_tab, fishing_bot`
- `254` (4): `self, exit_code, e, msg_box`
- `255` (13): `self, reason, telegram_settings, enabled, bot_token, chat_id, admin_ids_str, requests, message, url, payload, response, e`
- `256` (5): `self, expired_message, msg_box, dialog, result`

## config_manager
- `62` (2): `self, config_dir`
- `63` (3): `self, settings, fish_settings`
- `64` (3): `self, settings, garbage_settings`
- `65` (6): `self, default_settings, f, settings, merged, e`
- `66` (5): `self, settings, clean_settings, f, e`
- `67` (4): `self, settings, f, e`

## license.activation_dialog
- `232` (2): `.0, c`
- `233` (3): `.0, i, cleaned`
- `234` (2): `self, key`
- `235` (2): `key, self`
- `236` (1): `self`
- `238` (1): `__class__`
- `239` (4): `self, license_client, parent, __class__`
- `240` (5): `self, key, success, message, e`
- `241` (5): `self, text, cleaned, formatted, cursor_pos`
- `242` (2): `self, url`
- `243` (6): `self, message, status_type, color, html, scrollbar`
- `244` (20): `self, main_layout, title_label, subtitle_label, hwid_card, hwid_layout, hwid, hwid_title, hwid_value, key_label, button_layout, links_card, links_layout, links_title, tg_layout, tg_label, tg_link, fp_layout, fp_label, fp_link`

## license.license_client
- `275` (1): `__class__`
- `276` (2): `self, config_dir`
- `277` (4): `self, is_valid, message, e`
- `278` (7): `self, expires_at_str, expires_at, now, now_naive, is_valid, e`
- `279` (2): `self, encrypted_data`
- `280` (2): `self, e`
- `281` (2): `self, data`
- `282` (3): `self, reason, e`
- `283` (7): `self, f, encrypted, json_data, data, e, traceback`
- `284` (6): `self, license_data, json_data, encrypted, f, e`
- `285` (9): `self, license_key, url, data, response, result, expires_str, detail, e`
- `286` (1): `self`
- `287` (2): `self, expiration_callback`
- `288` (9): `self, url, data, response, result, detail, user_msg, frozen_msg, e`

## telegram.bot_manager
- `105` (1): `__class__`
- `106` (4): `self, token, admin_ids, log_callback`
- `107` (2): `self, message`
- `109` (4): `self, notification_manager, _network_error_handler, e`
- `110` (2): `self, e`
- `111` (1): `self`

## telegram.notification_manager
- `132` (1): `__class__`
- `133` (1): `self`
- `134` (4): `self, notification_type, settings, notifications`
- `135` (5): `self, text, photo, admin_id, e`
- `136` (4): `self, coro, running_loop, e`
- `137` (3): `self, bot, admin_ids`
- `138` (2): `self, text`
- `139` (6): `self, fish_name, screenshot_bytes, fish_name_ru, text, photo`
- `140` (4): `self, screenshot_bytes, text, photo`
- `141` (4): `self, fish_count, shutdown_pending, text`

## ui.fish_settings_dialog
- `167` (1): `__class__`
- `168` (14): `self, fish_name, fish_display_name, image_path, parent, layout, image_label, pixmap, scaled_pixmap, name_label, toggle_layout, release_label, keep_label, __class__`
- `169` (3): `self, parent, __class__`
- `170` (2): `self, card`
- `171` (4): `self, settings, fish_name, card`
- `172` (13): `self, layout, title, desc, quick_actions, select_all_btn, deselect_all_btn, scroll, scroll_widget, grid_layout, buttons_layout, cancel_btn, save_btn`
- `173` (1): `self`
- `174` (12): `self, grid_layout, fish_images_dir, fish_list, row, col, max_cols, fish_name, fish_display_name, fish_filename, image_path, card`
- `175` (3): `self, config, fish_settings`
- `176` (3): `self, fish_settings, config`
- `177` (2): `self, keep`
- `178` (4): `self, settings, fish_name, keep`

## ui.fishing_tab
- `306` (1): `self`
- `308` (1): `__class__`
- `309` (4): `self, fishing_bot, parent, __class__`
- `310` (5): `self, parent, FishingBot, set_fishing_bot, __class__`
- `311` (14): `self, settings, hotkey, listener_exists, has_is_alive, is_alive, is_running, has_callback, has_hotkey, listener_healthy, time, current_time, e, traceback`
- `312` (5): `self, is_alive, e, new_is_alive, traceback`
- `313` (5): `self, current_key, dialog, new_key, settings`
- `314` (5): `self, current_hotkey, dialog, new_hotkey, settings`
- `315` (3): `self, event, __class__`
- `316` (8): `self, title, description, layout, text_layout, title_label, desc_label, toggle`
- `317` (17): `self, main_layout, scroll, scroll_widget, scroll_layout, font, main_title, bait_layout, fish_settings_btn, garbage_settings_btn, meal_layout, backpack_layout, trunk_layout, shutdown_layout, hotkey_title, hotkey_btn, discard_key_btn`
- `318` (3): `self, settings, discard_key`
- `319` (3): `self, FishSettingsDialog, dialog`
- `320` (3): `self, GarbageSettingsDialog, dialog`
- `321` (3): `self, settings, current_config`
- `322` (2): `self, settings`
- `323` (3): `self, settings, hotkey`
- `324` (5): `self, initial_state, main_window, WindowActivator, e`

## ui.garbage_settings_dialog
- `169` (1): `__class__`
- `170` (14): `self, garbage_name, garbage_display_name, image_path, parent, layout, image_label, pixmap, scaled_pixmap, name_label, toggle_layout, keep_label, eject_label, __class__`
- `171` (3): `self, parent, __class__`
- `172` (2): `self, card`
- `173` (4): `self, settings, garbage_name, card`
- `174` (13): `self, layout, title, desc, quick_actions, select_all_btn, deselect_all_btn, scroll, scroll_widget, grid_layout, buttons_layout, cancel_btn, save_btn`
- `175` (1): `self`
- `176` (12): `self, grid_layout, garbage_images_dir, garbage_list, row, col, max_cols, garbage_name, garbage_display_name, garbage_filename, image_path, card`
- `177` (3): `self, config, garbage_settings`
- `178` (3): `self, garbage_settings, config`
- `179` (2): `self, eject`
- `180` (4): `self, settings, garbage_name, eject`

## ui.home_tab
- `287` (1): `self`
- `289` (1): `__class__`
- `290` (4): `self, license_client, parent, __class__`
- `291` (5): `self, text, re, url_pattern, html`
- `292` (5): `self, title, card, card_layout, title_label`
- `293` (6): `self, label_text, value_text, layout, label, value`
- `294` (2): `self, url`
- `295` (9): `self, promocode, requests, LicenseClient, response, data, message, error, e`
- `296` (24): `self, main_layout, scroll, scroll_content, scroll_layout, server_info_card, server_info_layout, promo_card, promo_layout, promo_input_layout, license_card, license_layout, status_row, expires_row, remaining_row, key_row, links_card, links_layout, tg_layout, tg_icon, tg_link, fp_layout, fp_icon, fp_link`
- `297` (10): `self, requests, LicenseClient, url, response, data, info_text, html_text, error_msg, e`
- `298` (15): `self, license_data, expires_at, expires_dt, local_dt, formatted_date, now, remaining, days, hours, minutes, remaining_text, e, key, masked_key`

## ui.hotkey_dialog
- `151` (1): `__class__`
- `152` (5): `self, current_hotkey, parent, title, __class__`
- `153` (3): `self, event, __class__`
- `154` (7): `self, keys, modifiers, regular_keys, key, key_name, parts`
- `155` (1): `self`
- `156` (4): `self, key, name, special`
- `157` (8): `self, layout, title, font, current, instructions, line, cancel_btn`
- `158` (3): `self, key, e`
- `159` (2): `self, display_text`

## ui.hotkey_listener
- `94` (3): `.0, vk, self`
- `96` (1): `self`
- `97` (2): `self, key`
- `98` (2): `self, vk`
- `99` (6): `self, hotkey_string, vks, part, key, vk`
- `100` (8): `self, vk_codes, callback, hotkey_name, triggered, all_down, e, traceback`
- `101` (3): `self, hotkey_string, callback`

## ui.ios_toggle
- `101` (1): `__class__`
- `102` (5): `self, parent, small, tiny, __class__`
- `103` (1): `self`
- `104` (2): `self, pos`
- `105` (2): `self, value`
- `106` (4): `self, event, painter, circle_y`

## ui.main_window
- `187` (1): `self`
- `189` (1): `__class__`
- `190` (8): `self, license_client, current_app, app_icon, candidates, icon_path, icon, __class__`
- `191` (3): `self, parent, __class__`
- `192` (4): `self, text, btn, font`
- `193` (2): `self, value`
- `194` (9): `self, central_widget, main_layout, sidebar, sidebar_layout, title_label, info_label, content_area, content_layout`
- `195` (4): `self, index, i, btn`
- `196` (2): `self, blur_radius`

## ui.telegram_tab
- `164` (1): `__class__`
- `165` (3): `self, fishing_tab, __class__`
- `166` (2): `self, settings`
- `167` (2): `self, event`
- `168` (19): `self, main_layout, scroll, scroll_widget, scroll_layout, title, title_font, instruction_frame, instruction_layout, instr_title, instr_title_font, instruction_text, settings_frame, settings_layout, token_label, token_label_font, ids_label, ids_label_font, ids_hint`
- `169` (2): `self, message`
- `170` (5): `self, token, admin_ids_str, admin_ids, fishing_bot`
- `171` (1): `self`

## workers.fishing.casting_a_fishing_rod
- `216` (1): `__class__`
- `217` (2): `self, roi`
- `218` (2): `self, process_name`
- `219` (9): `self, frame, x, y, w, h, region, hsv, mask`
- `220` (10): `self, frame, region, hsv, mask, coords, rx, ry, rw, rh`
- `221` (6): `hwnd, hwnds, _, pid, process, self`
- `222` (1): `self`
- `223` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `224` (11): `self, frame, now, remaining, count, bbox, bx, by, bw, bh, elapsed`
- `225` (2): `self, frame`
- `227` (5): `self, callback, hwnds, hwnd, title`
- `228` (5): `self, left, top, right, bottom`

## workers.fishing.fish_recognition
- `181` (1): `__class__`
- `182` (1): `self`
- `183` (2): `self, process_name`
- `184` (6): `hwnd, hwnds, _, pid, process, self`
- `185` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `186` (14): `self, screenshot, template, roi, search_area, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `187` (5): `self, callback, hwnds, hwnd, title`
- `188` (5): `self, left, top, right, bottom`
- `189` (3): `self, width, height`
- `190` (5): `self, template_path, fish_count, file_path, template`
- `192` (9): `self, screenshot, best_match, best_confidence, fish_template, found, x, y, confidence`
- `193` (4): `self, screenshot, fish_name, confidence`
- `194` (3): `self, fish_name, confidence`

## workers.fishing.fishing_bot
- `593` (3): `.0, t, current_triggers`
- `594` (2): `.0, v`
- `596` (1): `__class__`
- `597` (2): `self, log_callback`
- `598` (29): `self, triggers, boat_human, fishing_stages, ad_buttons, is_compiled, failed, has_boat, has_human, needs, current_hunger, current_thirst, events, current_advantage, current_pereves, e, notif_mgr, shutdown_pending, _time, os, current_changed_bait, current_gear, current_triggers, priority_trigger, now, wait_elapsed, prev_trigger, elapsed, finished_trigger`
- `599` (7): `self, Image, frame, frame_rgb, img, buf, e`
- `600` (13): `self, storer, STORE_ROI_2K, STORE_ROI_FHD, fish_stored_count, backpack_full, screenshot, fish_positions, total_fish_count, notif_mgr, fish_info, success, e`
- `601` (8): `self, roi, monitor, timeout, frame, green_count, _, pressed`
- `602` (2): `self, notif_mgr`
- `603` (5): `self, do_meal, do_backpack, garbage_settings, has_garbage_to_eject`
- `604` (1): `self`
- `605` (12): `self, fish_to_keep, fish_to_release, all_release, take_coord, release_coord, catch, eng_key, ru_name, weight, screenshot_bytes, notif_mgr`
- `606` (8): `self, disposal, GARB_ROI_2K, GARB_ROI_FHD, screenshot, garbage_list, g, e`
- `607` (15): `self, roi1, roi2, resolution_str, monitor, timeout, frame, red_count, color_diff, red_detected, change_detected, pressed, trigger_reason, fps, paused`
- `608` (13): `self, meal, INVENTORY_ROI_2K, FOOD_CHECK_ROI_2K, THIRST_CHECK_ROI_2K, INVENTORY_ROI_FULLHD, FOOD_CHECK_ROI_FULLHD, THIRST_CHECK_ROI_FULLHD, food_found, donuts_ok, cocktails_ok, e, notif_mgr`
- `609` (15): `self, meal, INVENTORY_ROI_2K, FOOD_CHECK_ROI_2K, THIRST_CHECK_ROI_2K, INVENTORY_ROI_FULLHD, FOOD_CHECK_ROI_FULLHD, THIRST_CHECK_ROI_FULLHD, food_found, donuts_ok, cocktails_ok, e, notif_mgr, garbage_settings, has_garbage_to_eject`
- `610` (14): `self, storer, STORE_ROI_2K, STORE_ROI_FHD, fish_stored_count, backpack_full, screenshot, fish_positions, fish_info, success, e, notif_mgr, garbage_settings, has_garbage_to_eject`
- `611` (21): `self, triggers, boat_human, triger_dir, change_boat_file, cv2, ROI_BOAT_HUMAN_FULLHD, ROI_BOAT_HUMAN_2K, roi, cx, cy, change_template, screenshot, result, _, max_val, max_loc, h, w, click_x, click_y`
- `612` (2): `self, fish_name_eng`
- `613` (3): `self, has_meal, has_backpack`
- `614` (8): `self, trigger_name, triggers, now, is_detected, last_seen, time_since_last, is_active`
- `615` (8): `self, fish_names_file, f, line, eng_name_with_png, ru_name, eng_name, e`
- `616` (4): `self, msg, ts, full_msg`
- `617` (5): `self, triger_dir, monitor, frame, detections`
- `618` (7): `self, roi, monitor, iterations, frame, result, e`
- `619` (19): `self, w, h, _, roi1, roi2, res_suffix, monitor, iterations, frame, red_conf, bubles_conf, red_det, bubles_det, pressed, reason, fps, paused, e`
- `620` (4): `self, tracker, iterations, state`
- `621` (3): `self, seconds, end`
- `622` (9): `self, WindowActivator, attempt, deadline, triggers, boat_human, stages, screenshot_bytes, notif_mgr`
- `623` (6): `self, max_retries, attempt, triggers, stages, deadline`
- `624` (7): `self, garbage_settings, WindowActivator, e, w, h, _`

## workers.fishing.garbage_disposal
- `261` (1): `__class__`
- `262` (1): `self`
- `263` (2): `self, process_name`
- `264` (6): `hwnd, hwnds, _, pid, process, self`
- `265` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `266` (13): `self, x, y, button, rect, client_rect, border_x, border_y, screen_x, screen_y, top_right_x, top_right_y, e`
- `267` (8): `self, garbage_info, garbage_name, garbage_x, garbage_y, garbage_num, key_to_press, e`
- `268` (11): `self, screenshot, found_garbage, garbage_types_to_search, garbage_key, matches, i, x, y, conf, garbage_info`
- `269` (16): `self, screenshot, template, roi, search_area, offset_x, offset_y, result, locations, matches, h, w, pt, confidence, center_x, center_y`
- `270` (14): `self, screenshot, template, roi, search_area, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `271` (5): `self, callback, hwnds, hwnd, title`
- `272` (5): `self, left, top, right, bottom`
- `273` (3): `self, width, height`
- `274` (6): `self, template_files, key, filename, file_path, template`
- `276` (16): `self, matches, template_w, template_h, filtered, min_distance, match, x, y, conf, is_overlap, existing, ex, ey, _, distance`
- `277` (8): `self, key, name, screenshot, garbage_positions, disposed_count, i, garbage_info`

## workers.fishing.hooking
- `215` (1): `__class__`
- `216` (4): `self, roi1, roi2, resolution_type`
- `217` (2): `self, process_name`
- `218` (6): `hwnd, hwnds, _, pid, process, self`
- `219` (1): `self`
- `220` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `221` (11): `self, frame, current_time, elapsed, remaining, red_confidence, red_detected, bubles_confidence, bubles_detected, pressed, trigger_reason`
- `223` (5): `self, callback, hwnds, hwnd, title`
- `224` (5): `self, left, top, right, bottom`
- `225` (2): `self, e`
- `227` (15): `self, frame, template, roi, x, y, w, h, roi_frame, result, min_val, max_val, min_loc, max_loc, pattern_detected`

## workers.fishing.meal_system
- `257` (1): `__class__`
- `258` (1): `self`
- `259` (2): `self, process_name`
- `260` (6): `hwnd, hwnds, _, pid, process, self`
- `261` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `262` (5): `self, screenshot, found, _, conf`
- `263` (7): `self, consumed_count, screenshot, found, x, y, conf`
- `264` (6): `self, screenshot, found, x, y, conf`
- `265` (4): `self, x, y, item_name`
- `266` (12): `self, x, y, rect, client_rect, border_x, border_y, screen_x, screen_y, win32api, original_pos, e`
- `267` (3): `self, screenshot, item_key`
- `268` (14): `self, screenshot, template, roi, search_area, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `269` (5): `self, callback, hwnds, hwnd, title`
- `270` (5): `self, left, top, right, bottom`
- `271` (3): `self, width, height`
- `272` (6): `self, template_files, key, filename, file_path, template`
- `274` (7): `self, screenshot, has_donut, _, has_cocktail, food_full, thirst_full`

## workers.fishing.memory_fish_reader
- `179` (1): `__class__`
- `180` (1): `self`
- `189` (17): `self, pids, targets, pid, h, regions, base, size, known_counts, current_counts, new_items, key, cnt, ru_name, weight, eng_key, _`
- `190` (5): `self, timeout, deadline, remaining, result`
- `191` (2): `self, timeout`

## workers.fishing.memory_reeling
- `311` (4): `.0, lo, hi, rs`
- `312` (4): `.0, lo, hi, vt`
- `313` (5): `.0, j, pb, comb, i`
- `315` (1): `__class__`
- `316` (3): `self, capture, log_callback`
- `317` (18): `self, hint_min, hint_max, key, cached, regions, addr, mbi, ret, rsz, rs, in_mod, re, cur, end, nxt, na, out`
- `318` (5): `self, cped_addr, half, lo, hi`
- `319` (4): `self, addr, d, v`
- `320` (20): `self, gta, base, size, vtable_ranges, nm, info, b, s, pattern, rp, il, offsets, m, raw, wp, cw, wo, cp, vt`
- `321` (34): `self, player_pos, by_hash, px, py, pz, hint_min, hint_max, regions, marker_delta, xmin, xmax, ymin, ymax, zmin, zmax, best, rs, re, data, n32, a32f, finite, m, hits4, idxs, i_np, i, xi, x, y, z, dist, addr`
- `322` (20): `self, player_pos, p_iface, p_ped_iface, max_peds, p_ped_list, px, py, pz, best, max_dist, max_dist2, i, ent_addr, h, pos, dx, dy, dz, d2`
- `323` (9): `self, gta, base, size, hit, rel, disp, ptr_addr, p_iface`
- `324` (8): `self, pid, snap, me, out, ok, name, base`
- `326` (2): `self, key`
- `327` (3): `self, addr, d`
- `328` (2): `self, msg`
- `329` (3): `self, source, now`
- `330` (11): `self, base, size, pattern, chunk, plen, prev, off, data, comb, i`
- `331` (5): `self, addr, size, buf, n`
- `332` (4): `self, ent_addr, archetype, d`
- `333` (9): `self, cped_addr, mat_off, raw, row, rv, rx, ry, ln`
- `334` (5): `self, addr, x, y, z`
- `335` (1): `self`
- `336` (21): `self, pp, fp, x, y, z, px, py, pz, dist, t_now, dt, dx, dy, vx, vy, vx_sm, vy_sm, right, lateral, move_val`

## workers.fishing.store_fish
- `235` (1): `__class__`
- `236` (1): `self`
- `237` (2): `self, process_name`
- `238` (6): `hwnd, hwnds, _, pid, process, self`
- `239` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `240` (13): `self, x, y, button, rect, client_rect, border_x, border_y, screen_x, screen_y, win32api, original_pos, e`
- `241` (9): `self, screenshot, found_fish, fish_template, found, fish_x, fish_y, confidence, fish_info`
- `242` (16): `self, screenshot, template, roi, search_area, search_gray, template_gray, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `243` (5): `self, callback, hwnds, hwnd, title`
- `244` (5): `self, left, top, right, bottom`
- `245` (3): `self, width, height`
- `246` (6): `self, template_path, remove_path, fish_count, file_path, template`
- `248` (6): `self, stored_count, screenshot, fish_positions, i, fish_info`
- `249` (10): `self, fish_info, fish_name, fish_x, fish_y, new_screenshot, found_remove, remove_x, remove_y, remove_conf`

## workers.fishing.trigger_monitor
- `275` (2): `.0, t`
- `277` (1): `__class__`
- `278` (3): `self, resolution, templates_dir`
- `279` (2): `self, process_name`
- `280` (7): `self, frame, roi, x, y, w, h`
- `281` (4): `self, filename, filepath, template`
- `282` (3): `self, templates, loaded`
- `283` (9): `self, roi, template, roi_gray, result, min_val, max_val, min_loc, max_loc`
- `284` (6): `hwnd, hwnds, _, pid, process, self`
- `285` (1): `self`
- `286` (15): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `287` (6): `self, frame, roi, detections, conf, loc`
- `289` (5): `self, callback, hwnds, hwnd, title`
- `291` (5): `self, left, top, right, bottom`
- `293` (5): `self, frame, current_time, elapsed, all_detections`

## workers.fishing.window_activator
- `95` (2): `__class__, KEYBDINPUT`
- `96` (2): `__class__, PUL`
- `97` (1): `__class__`

## workers.fishing.window_capture
- `116` (1): `__class__`
- `117` (2): `self, process_name`
- `118` (7): `self, x, y, rect, client_rect, border_x, border_y`
- `119` (6): `hwnd, hwnds, _, pid, process, self`
- `120` (1): `self`
- `121` (14): `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img`
- `122` (6): `self, x, y, button, screen_x, screen_y`
- `123` (5): `self, x, y, screen_x, screen_y`
- `124` (5): `self, callback, hwnds, hwnd, title`
- `125` (5): `self, left, top, right, bottom`
- `126` (2): `self, key`
