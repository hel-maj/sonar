/* ===== 23c60a570 license.activation_dialog:46 ===== */
/* ghidra_name=FUN_23c60a570 entry=23c60a570 size=50125 */

code * FUN_23c60a570(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  longlong *plVar18;
  ulonglong uVar19;
  longlong *local_120;
  longlong *local_118;
  longlong *local_110;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_d8;
  longlong *local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  longlong *local_a0;
  undefined4 local_98;
  longlong *local_80;
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  
  plVar18 = DAT_23ed6a4e0;
  lVar11 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar18 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar4 = _PyRuntime_exref;
  plVar7 = DAT_23ee29f60;
  plVar18[2] = lVar11;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar18[-1];
  puVar17 = *(undefined8 **)(lVar1 + 8);
  *puVar17 = plVar18 + -2;
  plVar18[-2] = lVar1;
  plVar18[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar17;
  *(longlong **)(lVar1 + 8) = plVar18 + -2;
  if (plVar7 == (longlong *)0x0) {
LAB_23c60a629:
    plVar7 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29f58,DAT_23ee29f70,0xa0);
    lVar11 = plVar18[2];
    DAT_23ee29f60 = plVar7;
  }
  else {
    lVar1 = *plVar7;
    if (1 < lVar1) {
      *plVar7 = lVar1 + -1;
      goto LAB_23c60a629;
    }
    if (plVar7[2] != 0) {
      *plVar7 = lVar1 + -1;
      if (lVar1 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c60a629;
    }
  }
  lVar1 = *(longlong *)(param_1 + 0x38);
  lVar14 = *(longlong *)(lVar1 + 8);
  plVar7[0xf] = lVar14;
  *(longlong **)(lVar1 + 8) = plVar7 + 9;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar7[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  lVar1 = DAT_23ee28fc8;
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  uVar2 = DAT_23ee28fc0;
  *(undefined4 *)(plVar7 + 5) = 0x30;
  plVar8 = (longlong *)FUN_23e915840(param_1,lVar11,uVar2,*(undefined8 *)(lVar1 + 0x18));
  if (plVar8 == (longlong *)0x0) {
    local_a0 = *(longlong **)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_98 = 0x30;
    local_a8 = *(longlong **)(param_1 + 0x68);
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    plVar10 = DAT_23ed6a4f8;
    goto joined_r0x00023c60e893;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  lVar11 = plVar18[2];
  *(undefined4 *)(plVar7 + 5) = 0x31;
  plVar8 = (longlong *)FUN_23e954670(param_1,lVar11,DAT_23ee28fd0);
  if (plVar8 == (longlong *)0x0) {
    local_a0 = *(longlong **)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_98 = 0x31;
    local_a8 = *(longlong **)(param_1 + 0x68);
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    plVar10 = DAT_23ed6a4f8;
    goto joined_r0x00023c60e893;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar18[2],DAT_23ee28fe0);
  pcVar4 = PyTuple_Type_exref;
  plVar8 = DAT_23ee28fe8;
  if (plVar9 == (longlong *)0x0) {
    local_a0 = *(longlong **)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_98 = 0x33;
    local_a8 = *(longlong **)(param_1 + 0x68);
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    plVar10 = DAT_23ed6a4f8;
    goto joined_r0x00023c60e893;
  }
  plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,0x1d);
  plVar10[3] = 0;
  plVar10[0x1f] = 0;
  puVar17 = (undefined8 *)((ulonglong)(plVar10 + 4) & 0xfffffffffffffff8);
  for (uVar19 = (ulonglong)
                (((int)plVar10 - (int)(undefined8 *)((ulonglong)(plVar10 + 4) & 0xfffffffffffffff8))
                 + 0x100U >> 3); uVar19 != 0; uVar19 = uVar19 - 1) {
    *puVar17 = 0;
    puVar17 = puVar17 + 1;
  }
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
  lVar1 = plVar10[-1];
  puVar17 = *(undefined8 **)(lVar11 + 8);
  *puVar17 = plVar10 + -2;
  plVar10[-2] = lVar11;
  plVar10[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar17;
  *(longlong **)(lVar11 + 8) = plVar10 + -2;
  lVar1 = DAT_23ee29728;
  *plVar8 = *plVar8 + 1;
  lVar11 = *(longlong *)(lVar1 + 0x20);
  plVar10[3] = (longlong)plVar8;
  if (*(char *)(lVar11 + 10) == '\0') {
    puVar17 = (undefined8 *)FUN_23a37a020(lVar1,DAT_23ee28ff0);
    if (puVar17 == (undefined8 *)0x0) goto LAB_23c60e719;
    plVar8 = (longlong *)*puVar17;
LAB_23c60f388:
    if (plVar8 == (longlong *)0x0) goto LAB_23c60e719;
LAB_23c60a845:
    plVar12 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar13 != (longlong *)0x0) {
        *plVar13 = *plVar13 + 1;
        DAT_23ed6a4c0 = plVar13;
        goto LAB_23c60a869;
      }
LAB_23c60f510:
      PyErr_PrintEx(0,0);
      Py_Exit(1);
LAB_23c60f528:
      local_a0 = *(longlong **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      local_98 = 0x3c;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_a8 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
LAB_23c60a869:
      plStack_70 = plVar12;
      local_78 = plVar8;
      lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
      if (lVar11 == 0) {
        local_a0 = *(longlong **)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        local_98 = 0x35;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_a8 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        plVar10[4] = lVar11;
        plVar8 = DAT_23ee28ff8;
        *DAT_23ee28ff8 = *DAT_23ee28ff8 + 1;
        plVar10[5] = (longlong)plVar8;
        plVar12 = (longlong *)FUN_23ead7550();
        plVar8 = DAT_23ed6cd28;
        if (plVar12 == (longlong *)0x0) {
          FUN_23e915740(param_1,&local_78,DAT_23ee29000);
          local_98 = 0x38;
          local_a0 = local_78;
          local_a8 = plStack_70;
          plVar8 = local_68;
        }
        else {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
            *plVar13 = *plVar13 + 1;
            DAT_23ed6a4c0 = plVar13;
          }
          plStack_70 = plVar8;
          local_78 = plVar12;
          lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
          if (lVar11 == 0) {
            local_a0 = *(longlong **)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            local_98 = 0x38;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            plVar10[6] = lVar11;
            plVar8 = DAT_23ee29008;
            *DAT_23ee29008 = *DAT_23ee29008 + 1;
            plVar10[7] = (longlong)plVar8;
            plVar12 = (longlong *)FUN_23ead76a0();
            plVar8 = DAT_23ed6cd28;
            if (plVar12 == (longlong *)0x0) {
              FUN_23e915740(param_1,&local_78,DAT_23ee29010);
              local_98 = 0x3b;
              local_a0 = local_78;
              local_a8 = plStack_70;
              plVar8 = local_68;
            }
            else {
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                *plVar13 = *plVar13 + 1;
                DAT_23ed6a4c0 = plVar13;
              }
              plStack_70 = plVar8;
              local_78 = plVar12;
              lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
              if (lVar11 == 0) {
                local_a0 = *(longlong **)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                local_98 = 0x3b;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_a8 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                plVar10[8] = lVar11;
                plVar8 = DAT_23ee29018;
                *DAT_23ee29018 = *DAT_23ee29018 + 1;
                plVar10[9] = (longlong)plVar8;
                plVar12 = (longlong *)FUN_23ead77f0();
                plVar8 = DAT_23ed6cd28;
                if (plVar12 == (longlong *)0x0) {
                  FUN_23e915740(param_1,&local_78,DAT_23ee29020);
                  local_98 = 0x3c;
                  local_a0 = local_78;
                  local_a8 = plStack_70;
                  plVar8 = local_68;
                }
                else {
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                    *plVar13 = *plVar13 + 1;
                    DAT_23ed6a4c0 = plVar13;
                  }
                  plStack_70 = plVar8;
                  local_78 = plVar12;
                  lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                  if (lVar11 == 0) goto LAB_23c60f528;
                  plVar10[10] = lVar11;
                  plVar8 = DAT_23ee29028;
                  *DAT_23ee29028 = *DAT_23ee29028 + 1;
                  plVar10[0xb] = (longlong)plVar8;
                  plVar12 = (longlong *)FUN_23ead7550();
                  plVar8 = DAT_23ed6cd28;
                  if (plVar12 == (longlong *)0x0) {
                    FUN_23e915740(param_1,&local_78,DAT_23ee29000);
                    local_98 = 0x3f;
                    local_a0 = local_78;
                    local_a8 = plStack_70;
                    plVar8 = local_68;
                  }
                  else {
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                      *plVar13 = *plVar13 + 1;
                      DAT_23ed6a4c0 = plVar13;
                    }
                    plStack_70 = plVar8;
                    local_78 = plVar12;
                    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                    if (lVar11 == 0) {
                      local_a0 = *(longlong **)(param_1 + 0x60);
                      plVar8 = *(longlong **)(param_1 + 0x70);
                      local_98 = 0x3f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_a8 = *(longlong **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      plVar10[0xc] = lVar11;
                      plVar8 = DAT_23ee29030;
                      *DAT_23ee29030 = *DAT_23ee29030 + 1;
                      plVar10[0xd] = (longlong)plVar8;
                      plVar12 = (longlong *)FUN_23ead6c20();
                      plVar8 = DAT_23ed6cd28;
                      if (plVar12 == (longlong *)0x0) {
                        FUN_23e915740(param_1,&local_78,DAT_23ee29038);
                        local_98 = 0x45;
                        local_a0 = local_78;
                        local_a8 = plStack_70;
                        plVar8 = local_68;
                      }
                      else {
                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                          plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                          if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                          *plVar13 = *plVar13 + 1;
                          DAT_23ed6a4c0 = plVar13;
                        }
                        plStack_70 = plVar8;
                        local_78 = plVar12;
                        lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                        if (lVar11 == 0) {
                          local_a0 = *(longlong **)(param_1 + 0x60);
                          plVar8 = *(longlong **)(param_1 + 0x70);
                          local_98 = 0x45;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          local_a8 = *(longlong **)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          plVar10[0xe] = lVar11;
                          plVar8 = DAT_23ee29040;
                          *DAT_23ee29040 = *DAT_23ee29040 + 1;
                          plVar10[0xf] = (longlong)plVar8;
                          plVar12 = (longlong *)FUN_23ead76a0();
                          plVar8 = DAT_23ed6cd28;
                          if (plVar12 == (longlong *)0x0) {
                            FUN_23e915740(param_1,&local_78,DAT_23ee29010);
                            local_98 = 0x48;
                            local_a0 = local_78;
                            local_a8 = plStack_70;
                            plVar8 = local_68;
                          }
                          else {
                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                              if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                              *plVar13 = *plVar13 + 1;
                              DAT_23ed6a4c0 = plVar13;
                            }
                            plStack_70 = plVar8;
                            local_78 = plVar12;
                            lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                            if (lVar11 == 0) {
                              local_a0 = *(longlong **)(param_1 + 0x60);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              local_98 = 0x48;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              local_a8 = *(longlong **)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              plVar10[0x10] = lVar11;
                              plVar8 = DAT_23ee29048;
                              *DAT_23ee29048 = *DAT_23ee29048 + 1;
                              plVar10[0x11] = (longlong)plVar8;
                              plVar12 = (longlong *)FUN_23ead7550();
                              plVar8 = DAT_23ed6cd28;
                              if (plVar12 == (longlong *)0x0) {
                                FUN_23e915740(param_1,&local_78,DAT_23ee29000);
                                local_98 = 0x49;
                                local_a0 = local_78;
                                local_a8 = plStack_70;
                                plVar8 = local_68;
                              }
                              else {
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                                  *plVar13 = *plVar13 + 1;
                                  DAT_23ed6a4c0 = plVar13;
                                }
                                plStack_70 = plVar8;
                                local_78 = plVar12;
                                lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                                if (lVar11 == 0) {
                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                  local_98 = 0x49;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar10[0x12] = lVar11;
                                  plVar8 = DAT_23ee29050;
                                  *DAT_23ee29050 = *DAT_23ee29050 + 1;
                                  plVar10[0x13] = (longlong)plVar8;
                                  plVar12 = (longlong *)FUN_23ead6c20();
                                  plVar8 = DAT_23ed6cd28;
                                  if (plVar12 == (longlong *)0x0) {
                                    FUN_23e915740(param_1,&local_78,DAT_23ee29038);
                                    local_98 = 0x5b;
                                    local_a0 = local_78;
                                    local_a8 = plStack_70;
                                    plVar8 = local_68;
                                  }
                                  else {
                                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                      plVar13 = (longlong *)
                                                PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                      if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                                      *plVar13 = *plVar13 + 1;
                                      DAT_23ed6a4c0 = plVar13;
                                    }
                                    plStack_70 = plVar8;
                                    local_78 = plVar12;
                                    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                                    if (lVar11 == 0) {
                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                      local_98 = 0x5b;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                    }
                                    else {
                                      plVar10[0x14] = lVar11;
                                      plVar8 = DAT_23ee29058;
                                      *DAT_23ee29058 = *DAT_23ee29058 + 1;
                                      plVar10[0x15] = (longlong)plVar8;
                                      plVar12 = (longlong *)FUN_23ead77f0();
                                      plVar8 = DAT_23ed6cd28;
                                      if (plVar12 == (longlong *)0x0) {
                                        FUN_23e915740(param_1,&local_78,DAT_23ee29020);
                                        local_98 = 0x65;
                                        local_a0 = local_78;
                                        local_a8 = plStack_70;
                                        plVar8 = local_68;
                                      }
                                      else {
                                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                          plVar13 = (longlong *)
                                                    PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                          if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                                          *plVar13 = *plVar13 + 1;
                                          DAT_23ed6a4c0 = plVar13;
                                        }
                                        plStack_70 = plVar8;
                                        local_78 = plVar12;
                                        lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                                        if (lVar11 == 0) {
                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                          local_98 = 0x65;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          plVar10[0x16] = lVar11;
                                          plVar8 = DAT_23ee29060;
                                          *DAT_23ee29060 = *DAT_23ee29060 + 1;
                                          plVar10[0x17] = (longlong)plVar8;
                                          plVar12 = (longlong *)FUN_23ead76a0();
                                          plVar8 = DAT_23ed6cd28;
                                          if (plVar12 == (longlong *)0x0) {
                                            FUN_23e915740(param_1,&local_78,DAT_23ee29010);
                                            local_98 = 0x6b;
                                            local_a0 = local_78;
                                            local_a8 = plStack_70;
                                            plVar8 = local_68;
                                          }
                                          else {
                                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                              plVar13 = (longlong *)
                                                        PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                              ;
                                              if (plVar13 == (longlong *)0x0) goto LAB_23c60f510;
                                              *plVar13 = *plVar13 + 1;
                                              DAT_23ed6a4c0 = plVar13;
                                            }
                                            plStack_70 = plVar8;
                                            local_78 = plVar12;
                                            lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
                                            if (lVar11 == 0) {
                                              local_a0 = *(longlong **)(param_1 + 0x60);
                                              plVar8 = *(longlong **)(param_1 + 0x70);
                                              local_98 = 0x6b;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              local_a8 = *(longlong **)(param_1 + 0x68);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              plVar10[0x18] = lVar11;
                                              plVar8 = DAT_23ee29068;
                                              *DAT_23ee29068 = *DAT_23ee29068 + 1;
                                              plVar10[0x19] = (longlong)plVar8;
                                              plVar12 = (longlong *)FUN_23ead77f0();
                                              plVar8 = DAT_23ed6cd28;
                                              if (plVar12 == (longlong *)0x0) {
                                                FUN_23e915740(param_1,&local_78,DAT_23ee29020);
                                                local_98 = 0x6c;
                                                local_a0 = local_78;
                                                local_a8 = plStack_70;
                                                plVar8 = local_68;
                                              }
                                              else {
                                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                  plVar13 = (longlong *)
                                                            PyDict_GetItemString
                                                                      (DAT_23ed6ccc0,"format");
                                                  if (plVar13 == (longlong *)0x0)
                                                  goto LAB_23c60f510;
                                                  *plVar13 = *plVar13 + 1;
                                                  DAT_23ed6a4c0 = plVar13;
                                                }
                                                plStack_70 = plVar8;
                                                local_78 = plVar12;
                                                lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,
                                                                       &local_78);
                                                if (lVar11 == 0) {
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  local_98 = 0x6c;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else {
                                                  plVar10[0x1a] = lVar11;
                                                  plVar8 = DAT_23ee29070;
                                                  *DAT_23ee29070 = *DAT_23ee29070 + 1;
                                                  plVar10[0x1b] = (longlong)plVar8;
                                                  plVar12 = (longlong *)FUN_23ead7550();
                                                  plVar8 = DAT_23ed6cd28;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    FUN_23e915740(param_1,&local_78,DAT_23ee29000);
                                                    local_98 = 0x6f;
                                                    local_a0 = local_78;
                                                    local_a8 = plStack_70;
                                                    plVar8 = local_68;
                                                  }
                                                  else {
                                                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                      plVar13 = (longlong *)
                                                                PyDict_GetItemString
                                                                          (DAT_23ed6ccc0,"format");
                                                      if (plVar13 == (longlong *)0x0)
                                                      goto LAB_23c60f510;
                                                      *plVar13 = *plVar13 + 1;
                                                      DAT_23ed6a4c0 = plVar13;
                                                    }
                                                    plStack_70 = plVar8;
                                                    local_78 = plVar12;
                                                    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,
                                                                           &local_78);
                                                    if (lVar11 == 0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      local_98 = 0x6f;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar10[0x1c] = lVar11;
                                                      plVar8 = DAT_23ee29078;
                                                      *DAT_23ee29078 = *DAT_23ee29078 + 1;
                                                      plVar10[0x1d] = (longlong)plVar8;
                                                      plVar12 = (longlong *)FUN_23ead76a0();
                                                      plVar8 = DAT_23ed6cd28;
                                                      if (plVar12 == (longlong *)0x0) {
                                                        FUN_23e915740(param_1,&local_78,
                                                                      DAT_23ee29010);
                                                        local_98 = 0x73;
                                                        local_a0 = local_78;
                                                        local_a8 = plStack_70;
                                                        plVar8 = local_68;
                                                      }
                                                      else {
                                                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                          plVar13 = (longlong *)
                                                                    PyDict_GetItemString
                                                                              (DAT_23ed6ccc0,
                                                                               "format");
                                                          if (plVar13 == (longlong *)0x0)
                                                          goto LAB_23c60f510;
                                                          *plVar13 = *plVar13 + 1;
                                                          DAT_23ed6a4c0 = plVar13;
                                                        }
                                                        plStack_70 = plVar8;
                                                        local_78 = plVar12;
                                                        lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0
                                                                               ,&local_78);
                                                        if (lVar11 != 0) {
                                                          plVar10[0x1e] = lVar11;
                                                          plVar8 = DAT_23ee29080;
                                                          *DAT_23ee29080 = *DAT_23ee29080 + 1;
                                                          plVar10[0x1f] = (longlong)plVar8;
                                                          plVar8 = (longlong *)
                                                                   PyUnicode_Join(DAT_23ed6cd28,
                                                                                  plVar10);
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            (**(code **)(plVar10[1] + 0x30))
                                                                      (plVar10);
                                                          }
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *plVar9 = *plVar9 + -1;
                                                            if (*plVar9 == 0) {
                                                              (**(code **)(plVar9[1] + 0x30))
                                                                        (plVar9);
                                                            }
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_120 = (longlong *)0x0;
                                                            plVar9 = (longlong *)0x0;
                                                            local_98 = 0x33;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0x33;
                                                          plVar12 = (longlong *)
                                                                    FUN_23e914090(param_1,plVar9,
                                                                                  plVar8);
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            (**(code **)(plVar8[1] + 0x30))();
                                                          }
                                                          if (plVar12 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            local_118 = (longlong *)0x0;
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_98 = 0x33;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            plVar9 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = *plVar12;
                                                          *plVar12 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            (**(code **)(plVar12[1] + 0x30))
                                                                      (plVar12);
                                                          }
                                                          lVar11 = FUN_23ead72b0();
                                                          if (lVar11 == 0) {
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            FUN_23e915740();
                                                            local_120 = (longlong *)0x0;
                                                            local_98 = 0x7a;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            plVar9 = (longlong *)0x0;
                                                            plVar8 = local_68;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            local_a8 = plStack_70;
                                                            local_a0 = local_78;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar1 = plVar18[2];
                                                          *(undefined4 *)(plVar7 + 5) = 0x7a;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e914090(param_1,lVar11,
                                                                                 lVar1);
                                                          lVar11 = DAT_23ee29098;
                                                          if (plVar9 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_98 = 0x7a;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0x7b;
                                                          plVar8 = (longlong *)
                                                                   FUN_23e95a860(param_1,plVar9,
                                                                                 DAT_23ee29090,
                                                                                 lVar11 + 0x18);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_98 = 0x7b;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0x7c;
                                                          plVar8 = (longlong *)
                                                                   FUN_23e915840(param_1,plVar9,
                                                                                 DAT_23ee290a0);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            local_110 = (longlong *)0x0;
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0x7c;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                                                          }
                                                          lVar11 = FUN_23ead7010();
                                                          if (lVar11 == 0) {
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            FUN_23e915740(param_1,&local_78);
                                                            local_120 = (longlong *)0x0;
                                                            local_98 = 0x7f;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            local_d0 = (longlong *)0x0;
                                                            plVar8 = local_68;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            local_a8 = plStack_70;
                                                            local_a0 = local_78;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0x7f;
                                                          local_d0 = (longlong *)
                                                                     FUN_23e94bb80(param_1,lVar11,
                                                                                   DAT_23ee290b8);
                                                          if (local_d0 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_118 = (longlong *)0x0;
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            local_f0 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_e0 = (longlong *)0x0;
                                                            local_98 = 0x7f;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          plVar12 = (longlong *)
                                                                    FUN_23e8bc2f0(local_d0,
                                                  DAT_23ee28fe0);
                                                  plVar8 = DAT_23ee290c0;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_98 = 0x80;
                                                    local_120 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_e0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *(longlong *)(param_1 + 0x10);
                                                  plVar10 = *(longlong **)(lVar11 + 0xe28);
                                                  if (plVar10 == (longlong *)0x0) {
                                                    plVar10 = (longlong *)FUN_23e916a20(pcVar4,3);
                                                  }
                                                  else {
                                                    lVar1 = plVar10[3];
                                                    *(int *)(lVar11 + 0xec0) =
                                                         *(int *)(lVar11 + 0xec0) + -1;
                                                    *(longlong *)(lVar11 + 0xe28) = lVar1;
                                                    *plVar10 = 1;
                                                  }
                                                  pcVar4 = _PyRuntime_exref;
                                                  *(undefined1 (*) [16])(plVar10 + 4) =
                                                       (undefined1  [16])0x0;
                                                  lVar11 = *(longlong *)
                                                            (*(longlong *)
                                                              (*(longlong *)(pcVar4 + 0x1f8) + 0x10)
                                                            + 0x2e8);
                                                  lVar1 = plVar10[-1];
                                                  puVar17 = *(undefined8 **)(lVar11 + 8);
                                                  *puVar17 = plVar10 + -2;
                                                  plVar10[-2] = lVar11;
                                                  plVar10[-1] = (ulonglong)((uint)lVar1 & 3) |
                                                                (ulonglong)puVar17;
                                                  *(longlong **)(lVar11 + 8) = plVar10 + -2;
                                                  *plVar8 = *plVar8 + 1;
                                                  plVar10[3] = (longlong)plVar8;
                                                  plVar13 = (longlong *)FUN_23ead6c20();
                                                  plVar8 = DAT_23ed6cd28;
                                                  if (plVar13 == (longlong *)0x0) {
                                                    FUN_23e915740(param_1,&local_78);
                                                    local_a0 = local_78;
                                                    local_a8 = plStack_70;
                                                    plVar8 = local_68;
                                                  }
                                                  else {
                                                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                      plVar15 = (longlong *)
                                                                PyDict_GetItemString
                                                                          (DAT_23ed6ccc0,"format");
                                                      if (plVar15 == (longlong *)0x0)
                                                      goto LAB_23c60f510;
                                                      *plVar15 = *plVar15 + 1;
                                                      DAT_23ed6a4c0 = plVar15;
                                                    }
                                                    plStack_70 = plVar8;
                                                    local_78 = plVar13;
                                                    lVar11 = FUN_23e94ed00(param_1);
                                                    if (lVar11 != 0) {
                                                      plVar10[4] = lVar11;
                                                      plVar8 = DAT_23ee290c8;
                                                      *DAT_23ee290c8 = *DAT_23ee290c8 + 1;
                                                      plVar10[5] = (longlong)plVar8;
                                                      plVar8 = (longlong *)
                                                               PyUnicode_Join(DAT_23ed6cd28,plVar10)
                                                      ;
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                      }
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        lVar11 = *plVar12;
                                                        *plVar12 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_120 = (longlong *)0x0;
                                                        local_98 = 0x80;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        local_e0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0x80;
                                                      plVar13 = (longlong *)
                                                                FUN_23e914090(param_1,plVar12);
                                                      lVar11 = *plVar12;
                                                      *plVar12 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        (**(code **)(plVar8[1] + 0x30))();
                                                      }
                                                      if (plVar13 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        local_110 = (longlong *)0x0;
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        plVar13 = (longlong *)0x0;
                                                        local_98 = 0x80;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        local_e0 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar11 = *plVar13;
                                                      *plVar13 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                                                      }
                                                      plVar10 = (longlong *)FUN_23e8bc2f0();
                                                      if (plVar10 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_98 = 0x86;
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        local_e0 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar11 = FUN_23ead7940();
                                                      if (lVar11 == 0) {
                                                        FUN_23e915740(param_1,&local_78,
                                                                      DAT_23ee28f90);
                                                        local_a8 = plStack_70;
                                                        local_a0 = local_78;
                                                        lVar11 = *plVar10;
                                                        *plVar10 = lVar11 + -1;
                                                        local_e0 = (longlong *)0x0;
                                                        plVar8 = local_68;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          local_120 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_98 = 0x86;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          local_d8 = (longlong *)0x0;
                                                          local_b0 = (longlong *)0x0;
                                                          local_c0 = (longlong *)0x0;
                                                          local_c8 = (longlong *)0x0;
                                                          local_b8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar15 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_98 = 0x86;
                                                          local_120 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          local_d8 = (longlong *)0x0;
                                                          local_b0 = (longlong *)0x0;
                                                          local_c0 = (longlong *)0x0;
                                                          local_c8 = (longlong *)0x0;
                                                          local_b8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar8 = (longlong *)
                                                               FUN_23e8bc2f0(lVar11,DAT_23ee290d8);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        lVar11 = *plVar10;
                                                        *plVar10 = lVar11 + -1;
                                                        local_e0 = (longlong *)0x0;
                                                        if (lVar11 + -1 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          FUN_23a334bc0(plVar10);
                                                          local_120 = (longlong *)0x0;
                                                          local_98 = 0x86;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          local_d8 = (longlong *)0x0;
                                                          local_b0 = (longlong *)0x0;
                                                          local_c0 = (longlong *)0x0;
                                                          local_c8 = (longlong *)0x0;
                                                          local_b8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_120 = (longlong *)0x0;
                                                          local_98 = 0x86;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          local_d8 = (longlong *)0x0;
                                                          local_b0 = (longlong *)0x0;
                                                          local_c0 = (longlong *)0x0;
                                                          local_c8 = (longlong *)0x0;
                                                          local_b8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar8);
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      if (plVar12 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        lVar11 = *plVar10;
                                                        *plVar10 = lVar11 + -1;
                                                        local_b8 = (longlong *)0x0;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                          local_120 = (longlong *)0x0;
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_98 = 0x86;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          local_d8 = (longlong *)0x0;
                                                          local_b0 = (longlong *)0x0;
                                                          local_c0 = (longlong *)0x0;
                                                          local_c8 = (longlong *)0x0;
                                                          local_e0 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar15 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          local_98 = 0x86;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_120 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          local_d8 = (longlong *)0x0;
                                                          local_b0 = (longlong *)0x0;
                                                          local_c0 = (longlong *)0x0;
                                                          local_c8 = (longlong *)0x0;
                                                          local_e0 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0x86;
                                                      plVar8 = (longlong *)
                                                               FUN_23e914090(param_1,plVar10,plVar12
                                                                            );
                                                      lVar11 = *plVar10;
                                                      *plVar10 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      lVar11 = *plVar12;
                                                      *plVar12 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 0x86;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        local_e0 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0x87;
                                                      plVar8 = (longlong *)
                                                               FUN_23e915840(param_1,plVar9,
                                                                             DAT_23ee290e8);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        local_110 = (longlong *)0x0;
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        plVar13 = (longlong *)0x0;
                                                        local_98 = 0x87;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_e0 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      lVar11 = FUN_23ead7010();
                                                      if (lVar11 == 0) {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        FUN_23e915740(param_1,&local_78);
                                                        local_120 = (longlong *)0x0;
                                                        local_98 = 0x8a;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        local_e0 = (longlong *)0x0;
                                                        plVar8 = local_68;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        local_a8 = plStack_70;
                                                        local_a0 = local_78;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0x8a;
                                                      local_e0 = (longlong *)
                                                                 FUN_23e94bb80(param_1,lVar11,
                                                                               DAT_23ee290f0);
                                                      if (local_e0 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_118 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_f0 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        local_98 = 0x8a;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar12 = (longlong *)
                                                                FUN_23e8bc2f0(local_e0,DAT_23ee28fe0
                                                                             );
                                                      plVar8 = DAT_23ee290f8;
                                                      if (plVar12 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_98 = 0x8b;
                                                        local_120 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_b0 = (longlong *)0x0;
                                                        local_c0 = (longlong *)0x0;
                                                        local_c8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_b8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar13 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),3);
                                                      *plVar8 = *plVar8 + 1;
                                                      plVar13[3] = (longlong)plVar8;
                                                      lVar11 = FUN_23ead6ec0();
                                                      if (lVar11 == 0) {
                                                        FUN_23e915740(param_1,&local_78);
                                                        local_a0 = local_78;
                                                        local_a8 = plStack_70;
                                                        plVar8 = local_68;
                                                      }
                                                      else {
                                                        lVar11 = FUN_23e94f9d0(param_1,lVar11);
                                                        if (lVar11 != 0) {
                                                          plVar13[4] = lVar11;
                                                          plVar8 = DAT_23ee29108;
                                                          *DAT_23ee29108 = *DAT_23ee29108 + 1;
                                                          plVar13[5] = (longlong)plVar8;
                                                          plVar8 = (longlong *)
                                                                   PyUnicode_Join(DAT_23ed6cd28,
                                                                                  plVar13);
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            lVar11 = *plVar12;
                                                            *plVar12 = lVar11 + -1;
                                                            if (lVar11 + -1 == 0) {
                                                              FUN_23a334bc0(plVar12);
                                                            }
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_120 = (longlong *)0x0;
                                                            local_98 = 0x8b;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0x8b;
                                                          plVar13 = (longlong *)
                                                                    FUN_23e914090(param_1,plVar12);
                                                          lVar11 = *plVar12;
                                                          *plVar12 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar13 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            local_110 = (longlong *)0x0;
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0x8b;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = *plVar13;
                                                          *plVar13 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          plVar10 = (longlong *)FUN_23e8bc2f0();
                                                          if (plVar10 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_98 = 0x90;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            local_d8 = (longlong *)0x0;
                                                            local_b0 = (longlong *)0x0;
                                                            local_c8 = (longlong *)0x0;
                                                            local_b8 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_c0 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = FUN_23ead7940();
                                                          if (lVar11 == 0) {
                                                            FUN_23e915740(param_1,&local_78,
                                                                          DAT_23ee28f90);
                                                            local_a8 = plStack_70;
                                                            local_a0 = local_78;
                                                            lVar11 = *plVar10;
                                                            *plVar10 = lVar11 + -1;
                                                            local_b8 = (longlong *)0x0;
                                                            plVar8 = local_68;
                                                            if (lVar11 + -1 == 0) {
                                                              FUN_23a334bc0();
                                                              plVar15 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_98 = 0x90;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              local_e8 = (longlong *)0x0;
                                                              local_d8 = (longlong *)0x0;
                                                              local_b0 = (longlong *)0x0;
                                                              local_c0 = (longlong *)0x0;
                                                              local_c8 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              plVar15 = (longlong *)0x0;
                                                              local_110 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_98 = 0x90;
                                                              local_120 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              local_e8 = (longlong *)0x0;
                                                              local_d8 = (longlong *)0x0;
                                                              local_b0 = (longlong *)0x0;
                                                              local_c0 = (longlong *)0x0;
                                                              local_c8 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          plVar8 = (longlong *)
                                                                   FUN_23e8bc2f0(lVar11,
                                                  DAT_23ee290d8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    lVar11 = *plVar10;
                                                    *plVar10 = lVar11 + -1;
                                                    local_b8 = (longlong *)0x0;
                                                    if (lVar11 + -1 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar10);
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0x90;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      local_e8 = (longlong *)0x0;
                                                      local_d8 = (longlong *)0x0;
                                                      local_b0 = (longlong *)0x0;
                                                      local_c0 = (longlong *)0x0;
                                                      local_c8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0x90;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      local_e8 = (longlong *)0x0;
                                                      local_d8 = (longlong *)0x0;
                                                      local_b0 = (longlong *)0x0;
                                                      local_c0 = (longlong *)0x0;
                                                      local_c8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar8);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    lVar11 = *plVar10;
                                                    *plVar10 = lVar11 + -1;
                                                    local_c8 = (longlong *)0x0;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                      local_120 = (longlong *)0x0;
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_98 = 0x90;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      local_e8 = (longlong *)0x0;
                                                      local_d8 = (longlong *)0x0;
                                                      local_b0 = (longlong *)0x0;
                                                      local_c0 = (longlong *)0x0;
                                                      local_b8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_98 = 0x90;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      local_e8 = (longlong *)0x0;
                                                      local_d8 = (longlong *)0x0;
                                                      local_b0 = (longlong *)0x0;
                                                      local_c0 = (longlong *)0x0;
                                                      local_b8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x90;
                                                  plVar8 = (longlong *)
                                                           FUN_23e914090(param_1,plVar10,plVar12);
                                                  lVar11 = *plVar10;
                                                  *plVar10 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0x90;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  lVar11 = DAT_23ee29118;
                                                  *(undefined4 *)(plVar7 + 5) = 0x91;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,local_e0,
                                                                         DAT_23ee29110,
                                                                         *(undefined8 *)
                                                                          (lVar11 + 0x18));
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0x91;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x92;
                                                  plVar8 = (longlong *)FUN_23e915840();
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0x92;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x95;
                                                  plVar8 = (longlong *)FUN_23e915840(param_1,plVar9)
                                                  ;
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0x95;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  lVar11 = FUN_23ead7400();
                                                  if (lVar11 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23e915740(param_1,&local_78,DAT_23ee29130);
                                                    local_98 = 0x98;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar8 = local_68;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    local_a8 = plStack_70;
                                                    local_a0 = local_78;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x98;
                                                  local_b8 = (longlong *)FUN_23e91a870();
                                                  if (local_b8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0x98;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x99;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,local_b8,
                                                                         DAT_23ee29138);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0x99;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  lVar11 = FUN_23ead72b0();
                                                  if (lVar11 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23e915740(param_1,&local_78,DAT_23ee29088);
                                                    local_98 = 0x9a;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    plVar8 = local_68;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    local_a8 = plStack_70;
                                                    local_a0 = local_78;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x9a;
                                                  local_c8 = (longlong *)FUN_23e914090();
                                                  lVar11 = DAT_23ee29148;
                                                  if (local_c8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0x9a;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x9b;
                                                  plVar8 = (longlong *)
                                                           FUN_23e95a860(param_1,local_c8,
                                                                         DAT_23ee29090,lVar11 + 0x18
                                                                        );
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0x9b;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x9c;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,local_c8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0x9c;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  plVar8 = (longlong *)FUN_23e8bc2f0();
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0x9e;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x9e;
                                                  local_c0 = (longlong *)
                                                             FUN_23e91bfe0(param_1,plVar8,
                                                                           DAT_23ee29158);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (local_c0 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0x9e;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = FUN_23ead7010();
                                                  if (lVar11 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    FUN_23e915740(param_1,&local_78,DAT_23ee290b0);
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_98 = 0x9f;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_120 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    plVar8 = local_68;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    local_a8 = plStack_70;
                                                    local_a0 = local_78;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0x9f;
                                                  local_b0 = (longlong *)
                                                             FUN_23e94bb80(param_1,lVar11);
                                                  if (local_b0 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0x9f;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar12 = (longlong *)FUN_23e8bc2f0(local_b0);
                                                  plVar8 = DAT_23ee29168;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_118 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_98 = 0xa0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar10 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),3);
                                                  *plVar8 = *plVar8 + 1;
                                                  plVar10[3] = (longlong)plVar8;
                                                  lVar11 = FUN_23ead6ec0();
                                                  if (lVar11 == 0) {
                                                    FUN_23e915740(param_1,&local_78);
                                                    local_a0 = local_78;
                                                    local_a8 = plStack_70;
                                                    plVar8 = local_68;
                                                  }
                                                  else {
                                                    lVar11 = FUN_23e94f9d0(param_1,lVar11);
                                                    if (lVar11 != 0) {
                                                      plVar10[4] = lVar11;
                                                      plVar8 = DAT_23ee29170;
                                                      *DAT_23ee29170 = *DAT_23ee29170 + 1;
                                                      plVar10[5] = (longlong)plVar8;
                                                      plVar8 = (longlong *)
                                                               PyUnicode_Join(DAT_23ed6cd28);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        lVar11 = *plVar12;
                                                        *plVar12 = lVar11 + -1;
                                                        local_d8 = (longlong *)0x0;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                          local_120 = (longlong *)0x0;
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_98 = 0xa0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_120 = (longlong *)0x0;
                                                          local_98 = 0xa0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          local_e8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xa0;
                                                      plVar13 = (longlong *)
                                                                FUN_23e914090(param_1,plVar12,plVar8
                                                                             );
                                                      lVar11 = *plVar12;
                                                      *plVar12 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      if (plVar13 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 0xa0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar11 = *plVar13;
                                                      *plVar13 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xa1;
                                                      plVar8 = (longlong *)
                                                               FUN_23e915840(param_1,local_c8,
                                                                             DAT_23ee290e8);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        local_110 = (longlong *)0x0;
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        plVar13 = (longlong *)0x0;
                                                        local_98 = 0xa1;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      lVar11 = FUN_23ead7010();
                                                      if (lVar11 == 0) {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        FUN_23e915740(param_1,&local_78);
                                                        local_120 = (longlong *)0x0;
                                                        local_98 = 0xa3;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        plVar8 = local_68;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        local_a8 = plStack_70;
                                                        local_a0 = local_78;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar8 = (longlong *)
                                                               FUN_23a38cc10(param_1,local_c0,
                                                                             DAT_23ee29178);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_118 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_f0 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_98 = 0xa3;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      lVar14 = FUN_23e94f9d0(param_1,plVar8);
                                                      lVar1 = *plVar8;
                                                      *plVar8 = lVar1 + -1;
                                                      if (lVar1 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      if (lVar14 == 0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_98 = 0xa3;
                                                        local_120 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar12 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),2);
                                                      plVar12[3] = lVar14;
                                                      plVar8 = DAT_23ee29180;
                                                      *DAT_23ee29180 = *DAT_23ee29180 + 1;
                                                      plVar12[4] = (longlong)plVar8;
                                                      plVar8 = (longlong *)
                                                               PyUnicode_Join(DAT_23ed6cd28,plVar12)
                                                      ;
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 0xa3;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        local_d8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xa3;
                                                      local_d8 = (longlong *)
                                                                 FUN_23e914090(param_1,lVar11,plVar8
                                                                              );
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      if (local_d8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_118 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_f0 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        local_98 = 0xa3;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar10 = (longlong *)
                                                                FUN_23e8bc2f0(local_d8,DAT_23ee28fe0
                                                                             );
                                                      plVar8 = DAT_23ee29188;
                                                      if (plVar10 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_98 = 0xa4;
                                                        local_120 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_e8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        goto joined_r0x00023c60e893;
                                                      }
                                                      plVar12 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),3);
                                                      *plVar8 = *plVar8 + 1;
                                                      plVar12[3] = (longlong)plVar8;
                                                      lVar11 = FUN_23ead7550();
                                                      if (lVar11 == 0) {
                                                        FUN_23e915740(param_1,&local_78);
                                                        local_a0 = local_78;
                                                        local_a8 = plStack_70;
                                                        plVar8 = local_68;
                                                      }
                                                      else {
                                                        lVar11 = FUN_23e94f9d0(param_1,lVar11);
                                                        if (lVar11 != 0) {
                                                          plVar12[4] = lVar11;
                                                          plVar8 = DAT_23ee29190;
                                                          *DAT_23ee29190 = *DAT_23ee29190 + 1;
                                                          plVar12[5] = (longlong)plVar8;
                                                          plVar8 = (longlong *)
                                                                   PyUnicode_Join(DAT_23ed6cd28,
                                                                                  plVar12);
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            lVar11 = *plVar10;
                                                            *plVar10 = lVar11 + -1;
                                                            local_e8 = (longlong *)0x0;
                                                            if (lVar11 + -1 == 0) {
                                                              plVar15 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              FUN_23a334bc0(plVar10);
                                                              local_98 = 0xa4;
                                                              local_120 = (longlong *)0x0;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              plVar15 = (longlong *)0x0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_98 = 0xa4;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0xa4;
                                                          plVar12 = (longlong *)
                                                                    FUN_23e914090(param_1,plVar10);
                                                          lVar11 = *plVar10;
                                                          *plVar10 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar12 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            local_110 = (longlong *)0x0;
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0xa4;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_118 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = *plVar12;
                                                          *plVar12 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          plVar10 = (longlong *)FUN_23e8bc2f0();
                                                          if (plVar10 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_98 = 0xa5;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_f0 = (longlong *)0x0;
                                                            local_e8 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_118 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          lVar11 = FUN_23ead7940();
                                                          if (lVar11 == 0) {
                                                            FUN_23e915740(param_1);
                                                            local_a8 = plStack_70;
                                                            local_a0 = local_78;
                                                            lVar11 = *plVar10;
                                                            *plVar10 = lVar11 + -1;
                                                            local_e8 = (longlong *)0x0;
                                                            plVar8 = local_68;
                                                            if (lVar11 + -1 == 0) {
                                                              FUN_23a334bc0();
                                                              plVar15 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_98 = 0xa5;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              plVar15 = (longlong *)0x0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_98 = 0xa5;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            goto joined_r0x00023c60e893;
                                                          }
                                                          plVar8 = (longlong *)
                                                                   FUN_23e8bc2f0(lVar11,
                                                  DAT_23ee291a0);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    lVar11 = *plVar10;
                                                    *plVar10 = lVar11 + -1;
                                                    local_e8 = (longlong *)0x0;
                                                    if (lVar11 + -1 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar10);
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0xa5;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0xa5;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar8);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    lVar11 = *plVar10;
                                                    *plVar10 = lVar11 + -1;
                                                    local_f0 = (longlong *)0x0;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                      local_120 = (longlong *)0x0;
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_98 = 0xa5;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_e8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_98 = 0xa5;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_e8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xa5;
                                                  plVar8 = (longlong *)
                                                           FUN_23e914090(param_1,plVar10,plVar12);
                                                  lVar11 = *plVar10;
                                                  *plVar10 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xa5;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xa6;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,local_c8,
                                                                         DAT_23ee290e8,local_d8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xa6;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xa8;
                                                  plVar8 = (longlong *)FUN_23e915840();
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xa8;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xaa;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,plVar9,
                                                                         DAT_23ee29120);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xaa;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  lVar11 = FUN_23ead7010();
                                                  if (lVar11 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23e915740(param_1,&local_78,DAT_23ee290b0);
                                                    local_98 = 0xad;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar8 = local_68;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    local_a8 = plStack_70;
                                                    local_a0 = local_78;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xad;
                                                  local_e8 = (longlong *)FUN_23e94bb80();
                                                  lVar11 = DAT_23ee291b8;
                                                  if (local_e8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xad;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xae;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,local_e8,
                                                                         DAT_23ee28fe0,
                                                                         *(undefined8 *)
                                                                          (lVar11 + 0x18));
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xae;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xaf;
                                                  plVar8 = (longlong *)
                                                           FUN_23e915840(param_1,plVar9,
                                                                         DAT_23ee290e8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xaf;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  lVar11 = *(longlong *)(DAT_23ee29728 + 0x20);
                                                  if (*(char *)(lVar11 + 10) == '\0') {
                                                    plVar8 = (longlong *)
                                                             FUN_23a37a020(DAT_23ee29728,
                                                                           DAT_23ee291c0);
                                                    if (plVar8 == (longlong *)0x0)
                                                    goto LAB_23c61497d;
                                                    lVar11 = *plVar8;
LAB_23c614974:
                                                    if (lVar11 == 0) goto LAB_23c61497d;
                                                  }
                                                  else {
                                                    iVar6 = *(int *)(lVar11 + 0xc);
                                                    if (*(int *)(lVar11 + 0xc) == 0) {
                                                      *(int *)(lVar11 + 0xc) = DAT_23ec12b2c;
                                                      iVar6 = DAT_23ec12b2c;
                                                      DAT_23ec12b2c = DAT_23ec12b2c + 1;
                                                    }
                                                    if (DAT_23ec12b28 != iVar6) {
                                                      DAT_23ec12b28 = iVar6;
                                                      DAT_23ee29f30 =
                                                           FUN_23e8cbd60(lVar11,DAT_23ee291c0,
                                                                         *(undefined8 *)
                                                                          (DAT_23ee291c0 + 0x18));
                                                    }
                                                    if (-1 < DAT_23ee29f30) {
                                                      lVar1 = lVar11 + 0x20 +
                                                              (1L << (*(byte *)(lVar11 + 9) & 0x3f))
                                                      ;
                                                      if (*(longlong *)
                                                           (lVar1 + 8 + DAT_23ee29f30 * 0x10) != 0)
                                                      goto LAB_23c60c123;
                                                      DAT_23ee29f30 =
                                                           FUN_23e8cbd60(lVar11,DAT_23ee291c0,
                                                                         *(undefined8 *)
                                                                          (DAT_23ee291c0 + 0x18));
                                                      if (-1 < DAT_23ee29f30) {
                                                        lVar11 = *(longlong *)
                                                                  (lVar1 + 8 + DAT_23ee29f30 * 0x10)
                                                        ;
                                                        goto LAB_23c614974;
                                                      }
                                                    }
LAB_23c61497d:
                                                    plVar8 = (longlong *)
                                                             FUN_23a37a020(DAT_23ed6ccc0,
                                                                           DAT_23ee291c0);
                                                    if ((plVar8 == (longlong *)0x0) ||
                                                       (*plVar8 == 0)) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      FUN_23e915740(param_1,&local_78);
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0xb1;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      plVar8 = local_68;
                                                      plVar10 = DAT_23ed6a4f8;
                                                      local_a8 = plStack_70;
                                                      local_a0 = local_78;
                                                      goto joined_r0x00023c60e893;
                                                    }
                                                  }
LAB_23c60c123:
                                                  *(undefined4 *)(plVar7 + 5) = 0xb1;
                                                  plVar8 = (longlong *)FUN_23e91a870(param_1);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb1;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  cVar5 = FUN_23e8d9ac0(plVar18[2],DAT_23ee291c8);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (cVar5 == '\0') {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_98 = 0xb1;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar8 = (longlong *)FUN_23e8bc2f0();
                                                  lVar11 = DAT_23ee291d8;
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xb2;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xb2;
                                                  plVar12 = (longlong *)
                                                            FUN_23e915840(param_1,plVar8,
                                                                          DAT_23ee291d0,
                                                                          *(undefined8 *)
                                                                           (lVar11 + 0x18));
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb2;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  plVar8 = (longlong *)
                                                           FUN_23e8bc2f0(plVar18[2],DAT_23ee291c8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xb3;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xb3;
                                                  plVar12 = (longlong *)FUN_23e915840(param_1);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xb3;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  plVar8 = (longlong *)
                                                           FUN_23e8bc2f0(plVar18[2],DAT_23ee291c8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb4;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar12 = (longlong *)
                                                            FUN_23e8bc2f0(plVar8,DAT_23ee291f0);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_110 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb4;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_120 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar12);
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar10 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_120 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xb4;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar8 = (longlong *)
                                                           FUN_23e8bc2f0(plVar18[2],DAT_23ee29200);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar10 = *plVar10 + -1;
                                                    local_f0 = (longlong *)0x0;
                                                    if (*plVar10 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar10);
                                                      local_98 = 0xb4;
                                                      local_120 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_98 = 0xb4;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xb4;
                                                  plVar12 = (longlong *)
                                                            FUN_23e914090(param_1,plVar10);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xb4;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  plVar8 = (longlong *)FUN_23e8bc2f0();
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xb5;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar12 = (longlong *)
                                                            FUN_23e8bc2f0(plVar8,DAT_23ee29208);
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb5;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar13 = (longlong *)
                                                            FUN_23e8bc2f0(plVar12,DAT_23ee291f8);
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  if (plVar13 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_98 = 0xb5;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar8 = (longlong *)FUN_23e8bc2f0();
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar13 = *plVar13 + -1;
                                                    local_f0 = (longlong *)0x0;
                                                    if (*plVar13 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      FUN_23a334bc0();
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0xb5;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_98 = 0xb5;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xb5;
                                                  plVar12 = (longlong *)
                                                            FUN_23e914090(param_1,plVar13);
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb5;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  plVar12 = (longlong *)
                                                            FUN_23e8bc2f0(plVar9,DAT_23ee290e8);
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xb6;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  plVar8 = (longlong *)FUN_23e8bc2f0(plVar18[2]);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    lVar11 = *plVar12;
                                                    *plVar12 = lVar11 + -1;
                                                    local_f0 = (longlong *)0x0;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                      local_120 = (longlong *)0x0;
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_98 = 0xb6;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0xb6;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *(undefined4 *)(plVar7 + 5) = 0xb6;
                                                  plVar13 = (longlong *)
                                                            FUN_23e914090(param_1,plVar12);
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  lVar11 = *plVar8;
                                                  *plVar8 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar13 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xb6;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                    goto joined_r0x00023c60e893;
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  lVar11 = *(longlong *)(DAT_23ee29728 + 0x20);
                                                  if (*(char *)(lVar11 + 10) == '\0') {
                                                    plVar8 = (longlong *)
                                                             FUN_23a37a020(DAT_23ee29728,
                                                                           DAT_23ee29218);
                                                    if (plVar8 == (longlong *)0x0)
                                                    goto LAB_23c613e9c;
                                                    lVar11 = *plVar8;
LAB_23c613e93:
                                                    if (lVar11 == 0) goto LAB_23c613e9c;
                                                  }
                                                  else {
                                                    iVar6 = *(int *)(lVar11 + 0xc);
                                                    if (*(int *)(lVar11 + 0xc) == 0) {
                                                      *(int *)(lVar11 + 0xc) = DAT_23ec12b2c;
                                                      iVar6 = DAT_23ec12b2c;
                                                      DAT_23ec12b2c = DAT_23ec12b2c + 1;
                                                    }
                                                    if (DAT_23ec12b30 != iVar6) {
                                                      DAT_23ec12b30 = iVar6;
                                                      DAT_23ee29f38 = FUN_23e8cbd60(lVar11);
                                                    }
                                                    if (-1 < DAT_23ee29f38) {
                                                      lVar1 = lVar11 + 0x20 +
                                                              (1L << (*(byte *)(lVar11 + 9) & 0x3f))
                                                      ;
                                                      if (*(longlong *)
                                                           (lVar1 + 8 + DAT_23ee29f38 * 0x10) != 0)
                                                      goto LAB_23c60c6ba;
                                                      DAT_23ee29f38 = FUN_23e8cbd60(lVar11);
                                                      if (-1 < DAT_23ee29f38) {
                                                        lVar11 = *(longlong *)
                                                                  (lVar1 + 8 + DAT_23ee29f38 * 0x10)
                                                        ;
                                                        goto LAB_23c613e93;
                                                      }
                                                    }
LAB_23c613e9c:
                                                    plVar8 = (longlong *)
                                                             FUN_23a37a020(DAT_23ed6ccc0,
                                                                           DAT_23ee29218);
                                                    if ((plVar8 == (longlong *)0x0) ||
                                                       (*plVar8 == 0)) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      FUN_23e915740(param_1,&local_78,DAT_23ee29218)
                                                      ;
                                                      local_98 = 0xb9;
                                                      local_120 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      plVar8 = local_68;
                                                      plVar10 = DAT_23ed6a4f8;
                                                      local_a8 = plStack_70;
                                                      local_a0 = local_78;
                                                      goto joined_r0x00023c60e893;
                                                    }
                                                  }
LAB_23c60c6ba:
                                                  *(undefined4 *)(plVar7 + 5) = 0xb9;
                                                  plVar8 = (longlong *)FUN_23e91a870(param_1);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xb9;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    cVar5 = FUN_23e8d9ac0(plVar18[2],DAT_23ee29220,
                                                                          plVar8);
                                                    lVar11 = *plVar8;
                                                    *plVar8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (cVar5 == '\0') {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      local_98 = 0xb9;
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      local_118 = (longlong *)0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_120 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_f0 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar8 = (longlong *)
                                                               FUN_23e8bc2f0(plVar18[2],
                                                                             DAT_23ee29220);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_98 = 0xba;
                                                        local_120 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_118 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 0xba;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e915840(param_1,plVar8);
                                                        lVar11 = *plVar8;
                                                        *plVar8 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar12 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          plVar15 = (longlong *)0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_98 = 0xba;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          lVar11 = *plVar12;
                                                          *plVar12 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          plVar8 = (longlong *)
                                                                   FUN_23e8bc2f0(plVar18[2]);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_f0 = (longlong *)0x0;
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            local_98 = 0xbb;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xbb;
                                                            plVar12 = (longlong *)
                                                                      FUN_23e915840(param_1,plVar8);
                                                            lVar11 = *plVar8;
                                                            *plVar8 = lVar11 + -1;
                                                            if (lVar11 + -1 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            if (plVar12 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              local_98 = 0xbb;
                                                              local_120 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              local_f0 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              lVar11 = *plVar12;
                                                              *plVar12 = lVar11 + -1;
                                                              if (lVar11 + -1 == 0) {
                                                                FUN_23a334bc0(plVar12);
                                                              }
                                                              plVar8 = (longlong *)
                                                                       FUN_23e8bc2f0(plVar18[2],
                                                                                     DAT_23ee29220);
                                                              if (plVar8 == (longlong *)0x0) {
                                                                local_a0 = *(longlong **)
                                                                            (param_1 + 0x60);
                                                                plVar8 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                                plVar15 = (longlong *)0x0;
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                plVar13 = (longlong *)0x0;
                                                                plVar12 = (longlong *)0x0;
                                                                local_98 = 0xbc;
                                                                local_a8 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                                local_120 = (longlong *)0x0;
                                                                local_110 = (longlong *)0x0;
                                                                local_108 = (longlong *)0x0;
                                                                local_100 = (longlong *)0x0;
                                                                local_f8 = (longlong *)0x0;
                                                                local_118 = (longlong *)0x0;
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                local_f0 = (longlong *)0x0;
                                                                plVar10 = DAT_23ed6a4f8;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xbc;
                                                                plVar12 = (longlong *)
                                                                          FUN_23e915840(param_1);
                                                                lVar11 = *plVar8;
                                                                *plVar8 = lVar11 + -1;
                                                                if (lVar11 + -1 == 0) {
                                                                  FUN_23a334bc0(plVar8);
                                                                }
                                                                if (plVar12 == (longlong *)0x0) {
                                                                  local_a0 = *(longlong **)
                                                                              (param_1 + 0x60);
                                                                  plVar8 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                                  local_f0 = (longlong *)0x0;
                                                                  plVar15 = (longlong *)0x0;
                                                                  plVar13 = (longlong *)0x0;
                                                                  plVar12 = (longlong *)0x0;
                                                                  local_a8 = *(longlong **)
                                                                              (param_1 + 0x68);
                                                                  local_98 = 0xbc;
                                                                  *(undefined1 (*) [16])
                                                                   (param_1 + 0x60) =
                                                                       (undefined1  [16])0x0;
                                                                  *(undefined8 *)(param_1 + 0x70) =
                                                                       0;
                                                                  local_120 = (longlong *)0x0;
                                                                  local_110 = (longlong *)0x0;
                                                                  local_108 = (longlong *)0x0;
                                                                  local_100 = (longlong *)0x0;
                                                                  local_f8 = (longlong *)0x0;
                                                                  local_118 = (longlong *)0x0;
                                                                  plVar10 = DAT_23ed6a4f8;
                                                                }
                                                                else {
                                                                  lVar11 = *plVar12;
                                                                  *plVar12 = lVar11 + -1;
                                                                  if (lVar11 + -1 == 0) {
                                                                    FUN_23a334bc0();
                                                                  }
                                                                  plVar10 = (longlong *)
                                                                            FUN_23e8bc2f0(plVar9,
                                                  DAT_23ee290e8);
                                                  if (plVar10 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_120 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_98 = 0xbd;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar8 = (longlong *)
                                                             FUN_23e8bc2f0(plVar18[2],DAT_23ee29220)
                                                    ;
                                                    if (plVar8 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      lVar11 = *plVar10;
                                                      *plVar10 = lVar11 + -1;
                                                      local_f0 = (longlong *)0x0;
                                                      if (lVar11 + -1 == 0) {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        FUN_23a334bc0(plVar10);
                                                        local_120 = (longlong *)0x0;
                                                        local_98 = 0xbd;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_98 = 0xbd;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_120 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 0xbd;
                                                      plVar12 = (longlong *)
                                                                FUN_23e914090(param_1,plVar10,plVar8
                                                                             );
                                                      lVar11 = *plVar10;
                                                      *plVar10 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar12 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        local_120 = (longlong *)0x0;
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_98 = 0xbd;
                                                        local_110 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        local_f0 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        lVar11 = FUN_23ead7160();
                                                        if (lVar11 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          FUN_23e915740(param_1,&local_78,
                                                                        DAT_23ee29248);
                                                          local_98 = 0xc0;
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          local_f0 = (longlong *)0x0;
                                                          plVar8 = local_68;
                                                          plVar10 = DAT_23ed6a4f8;
                                                          local_a8 = plStack_70;
                                                          local_a0 = local_78;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xc0;
                                                          local_f0 = (longlong *)
                                                                     FUN_23e91a870(param_1,lVar11);
                                                          if (local_f0 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            local_110 = (longlong *)0x0;
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0xc0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xc1;
                                                            plVar8 = (longlong *)
                                                                     FUN_23e915840(param_1,local_f0)
                                                            ;
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              local_110 = (longlong *)0x0;
                                                              plVar15 = (longlong *)0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plVar13 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_98 = 0xc1;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              local_120 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              local_118 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              lVar11 = *plVar8;
                                                              *plVar8 = lVar11 + -1;
                                                              if (lVar11 + -1 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              lVar11 = FUN_23ead6d70();
                                                              if (lVar11 == 0) {
                                                                plVar15 = (longlong *)0x0;
                                                                plVar13 = (longlong *)0x0;
                                                                plVar12 = (longlong *)0x0;
                                                                FUN_23e915740(param_1,&local_78,
                                                                              DAT_23ee29258);
                                                                local_110 = (longlong *)0x0;
                                                                local_108 = (longlong *)0x0;
                                                                local_100 = (longlong *)0x0;
                                                                local_f8 = (longlong *)0x0;
                                                                local_98 = 0xc3;
                                                                local_120 = (longlong *)0x0;
                                                                local_118 = (longlong *)0x0;
                                                                plVar8 = local_68;
                                                                plVar10 = DAT_23ed6a4f8;
                                                                local_a8 = plStack_70;
                                                                local_a0 = local_78;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xc3;
                                                                plVar8 = (longlong *)
                                                                         FUN_23e94bb80(param_1,
                                                  lVar11,DAT_23ee29260);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_98 = 0xc3;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    cVar5 = FUN_23e8d9ac0(plVar18[2],DAT_23ee29268);
                                                    lVar11 = *plVar8;
                                                    *plVar8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (cVar5 == '\0') {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      local_110 = (longlong *)0x0;
                                                      local_98 = 0xc3;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      local_120 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar8 = (longlong *)FUN_23e8bc2f0();
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        local_110 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_120 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_98 = 0xc4;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 0xc4;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e915840(param_1,plVar8);
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          FUN_23a334bc0(plVar8);
                                                        }
                                                        if (plVar12 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_98 = 0xc4;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          lVar11 = *plVar12;
                                                          *plVar12 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          plVar8 = (longlong *)
                                                                   FUN_23e8bc2f0(plVar18[2],
                                                                                 DAT_23ee29268);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_98 = 0xc5;
                                                            plVar13 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar12 = (longlong *)
                                                                      FUN_23e8bc2f0(plVar8,
                                                  DAT_23ee29278);
                                                  *plVar8 = *plVar8 + -1;
                                                  if (*plVar8 == 0) {
                                                    FUN_23a334bc0(plVar8);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_110 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xc5;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar12);
                                                    lVar11 = *plVar12;
                                                    *plVar12 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar10 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_98 = 0xc5;
                                                      local_120 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar8 = (longlong *)
                                                               FUN_23e8bc2f0(plVar18[2],
                                                                             DAT_23ee29210);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        lVar11 = *plVar10;
                                                        *plVar10 = lVar11 + -1;
                                                        local_118 = (longlong *)0x0;
                                                        if (lVar11 + -1 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          FUN_23a334bc0(plVar10);
                                                          local_98 = 0xc5;
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          local_120 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          local_98 = 0xc5;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 0xc5;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e914090(param_1,plVar10,
                                                                                plVar8);
                                                        lVar11 = *plVar10;
                                                        *plVar10 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        lVar11 = *plVar8;
                                                        *plVar8 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar12 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          plVar15 = (longlong *)0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_98 = 0xc5;
                                                          plVar13 = (longlong *)0x0;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          plVar8 = (longlong *)
                                                                   FUN_23e8bc2f0(plVar18[2],
                                                                                 DAT_23ee29268);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_110 = (longlong *)0x0;
                                                            plVar15 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0xc6;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xc6;
                                                            plVar12 = (longlong *)FUN_23e915840();
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            if (plVar12 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              local_110 = (longlong *)0x0;
                                                              plVar15 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              plVar12 = (longlong *)0x0;
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              local_120 = (longlong *)0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              local_98 = 0xc6;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              local_118 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              lVar11 = *plVar12;
                                                              *plVar12 = lVar11 + -1;
                                                              if (lVar11 + -1 == 0) {
                                                                FUN_23a334bc0(plVar12);
                                                              }
                                                              plVar12 = (longlong *)
                                                                        FUN_23e8bc2f0(local_f0,
                                                  DAT_23ee290e8);
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 199;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar8 = (longlong *)
                                                             FUN_23e8bc2f0(plVar18[2],DAT_23ee29268)
                                                    ;
                                                    if (plVar8 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *plVar12 = *plVar12 + -1;
                                                      local_118 = (longlong *)0x0;
                                                      if (*plVar12 == 0) {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        FUN_23a334bc0(plVar12);
                                                        local_98 = 199;
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_120 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 199;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 199;
                                                      plVar13 = (longlong *)
                                                                FUN_23e914090(param_1,plVar12);
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar13 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 199;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        lVar11 = *plVar13;
                                                        *plVar13 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        lVar11 = FUN_23ead6d70();
                                                        if (lVar11 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          FUN_23e915740(param_1,&local_78,
                                                                        DAT_23ee29258);
                                                          local_120 = (longlong *)0x0;
                                                          local_98 = 0xc9;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          plVar8 = local_68;
                                                          plVar10 = DAT_23ed6a4f8;
                                                          local_a8 = plStack_70;
                                                          local_a0 = local_78;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xc9;
                                                          plVar8 = (longlong *)
                                                                   FUN_23e94bb80(param_1,lVar11,
                                                                                 DAT_23ee29290);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_98 = 0xc9;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            cVar5 = FUN_23e8d9ac0(plVar18[2],
                                                                                  DAT_23ee29298);
                                                            lVar11 = *plVar8;
                                                            *plVar8 = lVar11 + -1;
                                                            if (lVar11 + -1 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            if (cVar5 == '\0') {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              local_98 = 0xc9;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plVar15 = (longlong *)0x0;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              plVar13 = (longlong *)0x0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              plVar8 = (longlong *)
                                                                       FUN_23e8bc2f0(plVar18[2],
                                                                                     DAT_23ee29298);
                                                              if (plVar8 == (longlong *)0x0) {
                                                                local_a0 = *(longlong **)
                                                                            (param_1 + 0x60);
                                                                plVar8 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                                local_110 = (longlong *)0x0;
                                                                plVar15 = (longlong *)0x0;
                                                                local_a8 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                                plVar13 = (longlong *)0x0;
                                                                local_98 = 0xca;
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                local_120 = (longlong *)0x0;
                                                                local_108 = (longlong *)0x0;
                                                                local_100 = (longlong *)0x0;
                                                                local_f8 = (longlong *)0x0;
                                                                local_118 = (longlong *)0x0;
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                plVar12 = (longlong *)0x0;
                                                                plVar10 = DAT_23ed6a4f8;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xca;
                                                                plVar12 = (longlong *)
                                                                          FUN_23e915840();
                                                                *plVar8 = *plVar8 + -1;
                                                                if (*plVar8 == 0) {
                                                                  FUN_23a334bc0();
                                                                }
                                                                if (plVar12 == (longlong *)0x0) {
                                                                  local_a0 = *(longlong **)
                                                                              (param_1 + 0x60);
                                                                  local_120 = (longlong *)0x0;
                                                                  plVar8 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                                  plVar15 = (longlong *)0x0;
                                                                  plVar13 = (longlong *)0x0;
                                                                  local_a8 = *(longlong **)
                                                                              (param_1 + 0x68);
                                                                  plVar12 = (longlong *)0x0;
                                                                  local_98 = 0xca;
                                                                  local_110 = (longlong *)0x0;
                                                                  *(undefined8 *)(param_1 + 0x70) =
                                                                       0;
                                                                  local_108 = (longlong *)0x0;
                                                                  local_100 = (longlong *)0x0;
                                                                  local_f8 = (longlong *)0x0;
                                                                  *(undefined1 (*) [16])
                                                                   (param_1 + 0x60) =
                                                                       (undefined1  [16])0x0;
                                                                  local_118 = (longlong *)0x0;
                                                                  plVar10 = DAT_23ed6a4f8;
                                                                }
                                                                else {
                                                                  lVar11 = *plVar12;
                                                                  *plVar12 = lVar11 + -1;
                                                                  if (lVar11 + -1 == 0) {
                                                                    FUN_23a334bc0();
                                                                  }
                                                                  plVar8 = (longlong *)
                                                                           FUN_23e8bc2f0(plVar18[2],
                                                                                                                                                                                  
                                                  DAT_23ee29298);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xcb;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar12 = (longlong *)
                                                              FUN_23e8bc2f0(plVar8,DAT_23ee29278);
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar12 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      local_120 = (longlong *)0x0;
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      local_98 = 0xcb;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      local_118 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar10 = (longlong *)
                                                                FUN_23e8bc2f0(plVar12,DAT_23ee291f8)
                                                      ;
                                                      lVar11 = *plVar12;
                                                      *plVar12 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      if (plVar10 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 0xcb;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_118 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        plVar8 = (longlong *)
                                                                 FUN_23e8bc2f0(plVar18[2],
                                                                               DAT_23ee292a8);
                                                        if (plVar8 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          lVar11 = *plVar10;
                                                          *plVar10 = lVar11 + -1;
                                                          local_118 = (longlong *)0x0;
                                                          if (lVar11 + -1 == 0) {
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            FUN_23a334bc0(plVar10);
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_98 = 0xcb;
                                                            local_120 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            local_120 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_98 = 0xcb;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xcb;
                                                          plVar12 = (longlong *)
                                                                    FUN_23e914090(param_1,plVar10,
                                                                                  plVar8);
                                                          lVar11 = *plVar10;
                                                          *plVar10 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar12 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0xcb;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            local_118 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *plVar12 = *plVar12 + -1;
                                                            if (*plVar12 == 0) {
                                                              FUN_23a334bc0(plVar12);
                                                            }
                                                            plVar8 = (longlong *)
                                                                     FUN_23e8bc2f0(plVar18[2],
                                                                                   DAT_23ee29298);
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              local_120 = (longlong *)0x0;
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              local_98 = 0xcc;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              local_118 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              *(undefined4 *)(plVar7 + 5) = 0xcc;
                                                              plVar12 = (longlong *)
                                                                        FUN_23e915840(param_1,plVar8
                                                                                     );
                                                              *plVar8 = *plVar8 + -1;
                                                              if (*plVar8 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              if (plVar12 == (longlong *)0x0) {
                                                                local_a0 = *(longlong **)
                                                                            (param_1 + 0x60);
                                                                plVar8 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                                local_110 = (longlong *)0x0;
                                                                plVar15 = (longlong *)0x0;
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                plVar13 = (longlong *)0x0;
                                                                plVar12 = (longlong *)0x0;
                                                                local_98 = 0xcc;
                                                                local_a8 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                                local_120 = (longlong *)0x0;
                                                                local_108 = (longlong *)0x0;
                                                                local_100 = (longlong *)0x0;
                                                                local_f8 = (longlong *)0x0;
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                local_118 = (longlong *)0x0;
                                                                plVar10 = DAT_23ed6a4f8;
                                                              }
                                                              else {
                                                                lVar11 = *plVar12;
                                                                *plVar12 = lVar11 + -1;
                                                                if (lVar11 + -1 == 0) {
                                                                  FUN_23a334bc0(plVar12);
                                                                }
                                                                plVar10 = (longlong *)
                                                                          FUN_23e8bc2f0();
                                                                if (plVar10 == (longlong *)0x0) {
                                                                  local_a0 = *(longlong **)
                                                                              (param_1 + 0x60);
                                                                  local_120 = (longlong *)0x0;
                                                                  plVar8 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                                  plVar15 = (longlong *)0x0;
                                                                  plVar13 = (longlong *)0x0;
                                                                  local_a8 = *(longlong **)
                                                                              (param_1 + 0x68);
                                                                  local_98 = 0xcd;
                                                                  local_110 = (longlong *)0x0;
                                                                  *(undefined8 *)(param_1 + 0x70) =
                                                                       0;
                                                                  local_108 = (longlong *)0x0;
                                                                  local_100 = (longlong *)0x0;
                                                                  local_f8 = (longlong *)0x0;
                                                                  local_118 = (longlong *)0x0;
                                                                  *(undefined1 (*) [16])
                                                                   (param_1 + 0x60) =
                                                                       (undefined1  [16])0x0;
                                                                  plVar12 = (longlong *)0x0;
                                                                  plVar10 = DAT_23ed6a4f8;
                                                                }
                                                                else {
                                                                  plVar8 = (longlong *)
                                                                           FUN_23e8bc2f0(plVar18[2],
                                                                                                                                                                                  
                                                  DAT_23ee29298);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar10 = *plVar10 + -1;
                                                    local_118 = (longlong *)0x0;
                                                    if (*plVar10 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar10);
                                                      local_98 = 0xcd;
                                                      local_120 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      local_98 = 0xcd;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xcd;
                                                    plVar12 = (longlong *)
                                                              FUN_23e914090(param_1,plVar10,plVar8);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    lVar11 = *plVar8;
                                                    *plVar8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar12 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      plVar13 = (longlong *)0x0;
                                                      local_98 = 0xcd;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      plVar12 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      local_118 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      lVar11 = *plVar12;
                                                      *plVar12 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xcf;
                                                      plVar8 = (longlong *)
                                                               FUN_23e915840(param_1,plVar9);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_110 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar12 = (longlong *)0x0;
                                                        local_98 = 0xcf;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_120 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_118 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        lVar11 = *plVar8;
                                                        *plVar8 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        lVar11 = FUN_23ead7400();
                                                        if (lVar11 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar12 = (longlong *)0x0;
                                                          FUN_23e915740(param_1,&local_78,
                                                                        DAT_23ee29130);
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          local_98 = 0xd2;
                                                          local_120 = (longlong *)0x0;
                                                          local_118 = (longlong *)0x0;
                                                          plVar8 = local_68;
                                                          plVar10 = DAT_23ed6a4f8;
                                                          local_a8 = plStack_70;
                                                          local_a0 = local_78;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xd2;
                                                          local_118 = (longlong *)
                                                                      FUN_23e91a870(param_1,lVar11);
                                                          if (local_118 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar12 = (longlong *)0x0;
                                                            local_98 = 0xd2;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            local_f8 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xd3;
                                                            plVar8 = (longlong *)
                                                                     FUN_23e915840(param_1,local_118
                                                                                   ,DAT_23ee29138);
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              local_98 = 0xd3;
                                                              local_120 = (longlong *)0x0;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              local_f8 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              plVar12 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              *plVar8 = *plVar8 + -1;
                                                              if (*plVar8 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              lVar11 = FUN_23ead72b0();
                                                              if (lVar11 == 0) {
                                                                plVar15 = (longlong *)0x0;
                                                                plVar13 = (longlong *)0x0;
                                                                FUN_23e915740(param_1,&local_78);
                                                                local_98 = 0xd4;
                                                                local_120 = (longlong *)0x0;
                                                                local_110 = (longlong *)0x0;
                                                                local_108 = (longlong *)0x0;
                                                                local_100 = (longlong *)0x0;
                                                                local_f8 = (longlong *)0x0;
                                                                plVar12 = (longlong *)0x0;
                                                                plVar8 = local_68;
                                                                plVar10 = DAT_23ed6a4f8;
                                                                local_a8 = plStack_70;
                                                                local_a0 = local_78;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xd4;
                                                                plVar12 = (longlong *)
                                                                          FUN_23e914090(param_1,
                                                  lVar11,local_118);
                                                  lVar11 = DAT_23ee292b8;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    local_120 = (longlong *)0x0;
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    local_98 = 0xd4;
                                                    local_110 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xd5;
                                                    plVar8 = (longlong *)
                                                             FUN_23e95a860(param_1,plVar12,
                                                                           DAT_23ee29090,
                                                                           lVar11 + 0x18);
                                                    if (plVar8 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_98 = 0xd5;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_120 = (longlong *)0x0;
                                                      local_110 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_f8 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xd6;
                                                      plVar8 = (longlong *)
                                                               FUN_23e915840(param_1,plVar12,
                                                                             DAT_23ee290a0);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        local_120 = (longlong *)0x0;
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        local_98 = 0xd6;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        local_f8 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        lVar11 = *plVar8;
                                                        *plVar8 = lVar11 + -1;
                                                        if (lVar11 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        lVar11 = FUN_23ead7010();
                                                        if (lVar11 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          FUN_23e915740(param_1,&local_78,
                                                                        DAT_23ee290b0);
                                                          local_98 = 0xd8;
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_f8 = (longlong *)0x0;
                                                          plVar8 = local_68;
                                                          plVar10 = DAT_23ed6a4f8;
                                                          local_a8 = plStack_70;
                                                          local_a0 = local_78;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xd8;
                                                          local_f8 = (longlong *)FUN_23e94bb80();
                                                          if (local_f8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0xd8;
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            local_100 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar13 = (longlong *)
                                                                      FUN_23e8bc2f0(local_f8,
                                                  DAT_23ee28fe0);
                                                  plVar8 = DAT_23ee292d0;
                                                  if (plVar13 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xd9;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar10 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),3);
                                                    *plVar8 = *plVar8 + 1;
                                                    plVar10[3] = (longlong)plVar8;
                                                    lVar11 = FUN_23ead6c20();
                                                    if (lVar11 == 0) {
                                                      FUN_23e915740(param_1,&local_78,DAT_23ee29038)
                                                      ;
                                                      local_a0 = local_78;
                                                      local_a8 = plStack_70;
                                                      plVar8 = local_68;
                                                    }
                                                    else {
                                                      lVar11 = FUN_23e94f9d0(param_1,lVar11);
                                                      if (lVar11 != 0) {
                                                        plVar10[4] = lVar11;
                                                        plVar8 = DAT_23ee292d8;
                                                        *DAT_23ee292d8 = *DAT_23ee292d8 + 1;
                                                        plVar10[5] = (longlong)plVar8;
                                                        plVar8 = (longlong *)
                                                                 PyUnicode_Join(DAT_23ed6cd28,
                                                                                plVar10);
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        if (plVar8 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          lVar11 = *plVar13;
                                                          *plVar13 = lVar11 + -1;
                                                          local_100 = (longlong *)0x0;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                            plVar15 = (longlong *)0x0;
                                                            local_120 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            local_98 = 0xd9;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            local_120 = (longlong *)0x0;
                                                            local_98 = 0xd9;
                                                            local_110 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xd9;
                                                          plVar15 = (longlong *)
                                                                    FUN_23e914090(param_1,plVar13,
                                                                                  plVar8);
                                                          lVar11 = *plVar13;
                                                          *plVar13 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          lVar11 = *plVar8;
                                                          *plVar8 = lVar11 + -1;
                                                          if (lVar11 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar15 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            local_120 = (longlong *)0x0;
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            local_98 = 0xd9;
                                                            local_108 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_100 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            local_110 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            lVar11 = *plVar15;
                                                            *plVar15 = lVar11 + -1;
                                                            if (lVar11 + -1 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            *(undefined4 *)(plVar7 + 5) = 0xda;
                                                            plVar8 = (longlong *)
                                                                     FUN_23e915840(param_1,plVar12);
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              local_98 = 0xda;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              local_120 = (longlong *)0x0;
                                                              local_110 = (longlong *)0x0;
                                                              local_108 = (longlong *)0x0;
                                                              local_100 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              lVar11 = *plVar8;
                                                              *plVar8 = lVar11 + -1;
                                                              if (lVar11 + -1 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              lVar11 = FUN_23ead7160();
                                                              if (lVar11 == 0) {
                                                                plVar15 = (longlong *)0x0;
                                                                plVar13 = (longlong *)0x0;
                                                                FUN_23e915740(param_1,&local_78,
                                                                              DAT_23ee29248);
                                                                local_120 = (longlong *)0x0;
                                                                local_98 = 0xdd;
                                                                local_110 = (longlong *)0x0;
                                                                local_108 = (longlong *)0x0;
                                                                local_100 = (longlong *)0x0;
                                                                plVar8 = local_68;
                                                                plVar10 = DAT_23ed6a4f8;
                                                                local_a8 = plStack_70;
                                                                local_a0 = local_78;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xdd;
                                                                local_100 = (longlong *)
                                                                            FUN_23e91a870(param_1,
                                                  lVar11);
                                                  if (local_100 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xdd;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xde;
                                                    plVar8 = (longlong *)
                                                             FUN_23e915840(param_1,local_100,
                                                                           DAT_23ee290a0);
                                                    if (plVar8 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      local_120 = (longlong *)0x0;
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      local_98 = 0xde;
                                                      local_110 = (longlong *)0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      local_108 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      lVar11 = *plVar8;
                                                      *plVar8 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      lVar11 = FUN_23ead7010();
                                                      if (lVar11 == 0) {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        FUN_23e915740(param_1,&local_78,
                                                                      DAT_23ee290b0);
                                                        local_98 = 0xdf;
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        plVar8 = local_68;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        local_a8 = plStack_70;
                                                        local_a0 = local_78;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 0xdf;
                                                        local_108 = (longlong *)
                                                                    FUN_23e94bb80(param_1,lVar11,
                                                                                  DAT_23ee292e0);
                                                        if (local_108 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          plVar15 = (longlong *)0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_98 = 0xdf;
                                                          plVar13 = (longlong *)0x0;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          local_120 = (longlong *)0x0;
                                                          local_110 = (longlong *)0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar10 = (longlong *)
                                                                    FUN_23e8bc2f0(local_108,
                                                                                  DAT_23ee28fe0);
                                                          plVar8 = DAT_23ee292e8;
                                                          if (plVar10 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_98 = 0xe0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            local_120 = (longlong *)0x0;
                                                            local_110 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar13 = (longlong *)
                                                                      FUN_23e916ad0(*(undefined8 *)
                                                                                     (param_1 + 0x10
                                                                                     ),3);
                                                            *plVar8 = *plVar8 + 1;
                                                            plVar13[3] = (longlong)plVar8;
                                                            lVar11 = FUN_23ead6ec0();
                                                            if (lVar11 == 0) {
                                                              FUN_23e915740(param_1,&local_78);
                                                              local_a0 = local_78;
                                                              local_a8 = plStack_70;
                                                              plVar8 = local_68;
                                                            }
                                                            else {
                                                              lVar11 = FUN_23e94f9d0(param_1,lVar11)
                                                              ;
                                                              if (lVar11 != 0) {
                                                                plVar13[4] = lVar11;
                                                                plVar8 = DAT_23ee292f0;
                                                                *DAT_23ee292f0 = *DAT_23ee292f0 + 1;
                                                                plVar13[5] = (longlong)plVar8;
                                                                plVar8 = (longlong *)
                                                                         PyUnicode_Join(
                                                  DAT_23ed6cd28,plVar13);
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar10 = *plVar10 + -1;
                                                    local_110 = (longlong *)0x0;
                                                    if (*plVar10 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar10);
                                                      local_98 = 0xe0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_98 = 0xe0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xe0;
                                                    plVar13 = (longlong *)
                                                              FUN_23e914090(param_1,plVar10,plVar8);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    lVar11 = *plVar8;
                                                    *plVar8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar13 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_98 = 0xe0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_110 = (longlong *)0x0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      lVar11 = *plVar13;
                                                      *plVar13 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      lVar11 = FUN_23ead6d70();
                                                      if (lVar11 == 0) {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        FUN_23e915740(param_1,&local_78,
                                                                      DAT_23ee29258);
                                                        local_98 = 0xe1;
                                                        local_120 = (longlong *)0x0;
                                                        local_110 = (longlong *)0x0;
                                                        plVar8 = local_68;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        local_a8 = plStack_70;
                                                        local_a0 = local_78;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 0xe1;
                                                        local_110 = (longlong *)
                                                                    FUN_23e94bb80(param_1,lVar11,
                                                                                  DAT_23ee292f8);
                                                        if (local_110 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          local_120 = (longlong *)0x0;
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          plVar15 = (longlong *)0x0;
                                                          plVar13 = (longlong *)0x0;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          local_98 = 0xe1;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          plVar13 = (longlong *)
                                                                    FUN_23e8bc2f0(local_110,
                                                                                  DAT_23ee28fe0);
                                                          plVar8 = DAT_23ee29300;
                                                          if (plVar13 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_120 = (longlong *)0x0;
                                                            plVar15 = (longlong *)0x0;
                                                            local_98 = 0xe2;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar13 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar15 = (longlong *)
                                                                      FUN_23e916ad0(*(undefined8 *)
                                                                                     (param_1 + 0x10
                                                                                     ),3);
                                                            *plVar8 = *plVar8 + 1;
                                                            plVar15[3] = (longlong)plVar8;
                                                            lVar11 = FUN_23ead6c20();
                                                            if (lVar11 == 0) {
                                                              FUN_23e915740(param_1,&local_78,
                                                                            DAT_23ee29038);
                                                              local_a0 = local_78;
                                                              local_a8 = plStack_70;
                                                              plVar8 = local_68;
                                                            }
                                                            else {
                                                              lVar11 = FUN_23e94f9d0(param_1,lVar11)
                                                              ;
                                                              if (lVar11 != 0) {
                                                                plVar15[4] = lVar11;
                                                                plVar8 = DAT_23ee29308;
                                                                *DAT_23ee29308 = *DAT_23ee29308 + 1;
                                                                plVar15[5] = (longlong)plVar8;
                                                                plVar8 = (longlong *)
                                                                         PyUnicode_Join(
                                                  DAT_23ed6cd28);
                                                  *plVar15 = *plVar15 + -1;
                                                  if (*plVar15 == 0) {
                                                    FUN_23a334bc0(plVar15);
                                                  }
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    plVar13 = (longlong *)0x0;
                                                    local_98 = 0xe2;
                                                    local_120 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xe2;
                                                    plVar15 = (longlong *)
                                                              FUN_23e914090(param_1,plVar13,plVar8);
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar15 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      local_98 = 0xe2;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_120 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      lVar11 = *plVar15;
                                                      *plVar15 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      plVar10 = (longlong *)
                                                                FUN_23e8bc2f0(local_110,
                                                                              DAT_23ee29310);
                                                      if (plVar10 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        plVar13 = (longlong *)0x0;
                                                        local_98 = 0xf1;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_120 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        lVar11 = FUN_23ead7940();
                                                        if (lVar11 == 0) {
                                                          FUN_23e915740(param_1,&local_78,
                                                                        DAT_23ee28f90);
                                                          local_a8 = plStack_70;
                                                          local_a0 = local_78;
                                                          *plVar10 = *plVar10 + -1;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar8 = local_68;
                                                          if (*plVar10 == 0) {
                                                            plVar15 = (longlong *)0x0;
                                                            FUN_23a334bc0(plVar10);
                                                            local_98 = 0xf1;
                                                            local_120 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            plVar15 = (longlong *)0x0;
                                                            local_120 = (longlong *)0x0;
                                                            local_98 = 0xf1;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                        }
                                                        else {
                                                          plVar8 = (longlong *)
                                                                   FUN_23e8bc2f0(lVar11,
                                                  DAT_23ee29318);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *plVar10 = *plVar10 + -1;
                                                    plVar13 = (longlong *)0x0;
                                                    if (*plVar10 == 0) {
                                                      plVar15 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar10);
                                                      local_98 = 0xf1;
                                                      local_120 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)0x0;
                                                      local_98 = 0xf1;
                                                      local_120 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                  }
                                                  else {
                                                    plVar13 = (longlong *)
                                                              FUN_23e8bc2f0(plVar8,DAT_23ee29320);
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar13 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar10 = *plVar10 + -1;
                                                      local_120 = (longlong *)0x0;
                                                      if (*plVar10 == 0) {
                                                        plVar13 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        FUN_23a334bc0(plVar10);
                                                        local_98 = 0xf1;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        plVar15 = (longlong *)0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        local_98 = 0xf1;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 0xf1;
                                                      plVar8 = (longlong *)
                                                               FUN_23e914090(param_1,plVar10);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      lVar11 = *plVar13;
                                                      *plVar13 = lVar11 + -1;
                                                      if (lVar11 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_120 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        local_98 = 0xf1;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          FUN_23a334bc0(plVar8);
                                                        }
                                                        plVar8 = (longlong *)FUN_23e8bc2f0();
                                                        uVar2 = DAT_23ee29f70;
                                                        if (plVar8 != (longlong *)0x0) {
                                                          *plVar18 = *plVar18 + 1;
                                                          local_78 = plVar18;
                                                          plVar13 = (longlong *)
                                                                    FUN_23e93e1e0(FUN_23c6169f0,
                                                                                  DAT_23ee29328,
                                                                                  DAT_23ee29330,
                                                                                  DAT_23ee29f40,0,0,
                                                                                  uVar2,0,&local_78,
                                                                                  1);
                                                          *(undefined4 *)(plVar7 + 5) = 0xf2;
                                                          plVar15 = (longlong *)
                                                                    FUN_23e915840(param_1,plVar8,
                                                                                  DAT_23ee291f8,
                                                                                  plVar13);
                                                          *plVar8 = *plVar8 + -1;
                                                          if (*plVar8 == 0) {
                                                            FUN_23a334bc0(plVar8);
                                                          }
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          if (plVar15 != (longlong *)0x0) {
                                                            *plVar15 = *plVar15 + -1;
                                                            if (*plVar15 == 0) {
                                                              FUN_23a334bc0(plVar15);
                                                            }
                                                            *(undefined4 *)(plVar7 + 5) = 0xf3;
                                                            plVar8 = (longlong *)
                                                                     FUN_23e915840(param_1,local_100
                                                                                   ,DAT_23ee290e8,
                                                                                   local_108);
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              local_98 = 0xf3;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar13 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              *plVar8 = *plVar8 + -1;
                                                              if (*plVar8 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              *(undefined4 *)(plVar7 + 5) = 0xf4;
                                                              plVar8 = (longlong *)
                                                                       FUN_23e915840(param_1,
                                                  local_100,DAT_23ee290e8);
                                                  if (plVar8 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_98 = 0xf4;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_120 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    *(undefined4 *)(plVar7 + 5) = 0xf5;
                                                    plVar8 = (longlong *)
                                                             FUN_23e91bfe0(param_1,local_100,
                                                                           DAT_23ee29338);
                                                    if (plVar8 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      local_120 = (longlong *)0x0;
                                                      plVar15 = (longlong *)0x0;
                                                      local_98 = 0xf5;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar13 = (longlong *)0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xf6;
                                                      plVar8 = (longlong *)
                                                               FUN_23e915840(param_1,plVar12,
                                                                             DAT_23ee292b0,local_100
                                                                            );
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_120 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        local_98 = 0xf6;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar13 = (longlong *)0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          FUN_23a334bc0(plVar8);
                                                        }
                                                        lVar11 = FUN_23ead7160();
                                                        if (lVar11 == 0) {
                                                          plVar15 = (longlong *)0x0;
                                                          FUN_23e915740(param_1,&local_78,
                                                                        DAT_23ee29248);
                                                          local_120 = (longlong *)0x0;
                                                          local_98 = 0xf9;
                                                          plVar13 = (longlong *)0x0;
                                                          plVar8 = local_68;
                                                          plVar10 = DAT_23ed6a4f8;
                                                          local_a8 = plStack_70;
                                                          local_a0 = local_78;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xf9;
                                                          plVar13 = (longlong *)
                                                                    FUN_23e91a870(param_1,lVar11);
                                                          lVar11 = DAT_23ee29128;
                                                          if (plVar13 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            plVar15 = (longlong *)0x0;
                                                            local_98 = 0xf9;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_120 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xfa;
                                                            plVar8 = (longlong *)
                                                                     FUN_23e915840(param_1,plVar13,
                                                                                   DAT_23ee290a0,
                                                                                   *(undefined8 *)
                                                                                    (lVar11 + 0x18))
                                                            ;
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              local_98 = 0xfa;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              local_120 = (longlong *)0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              lVar11 = *plVar8;
                                                              *plVar8 = lVar11 + -1;
                                                              if (lVar11 + -1 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              lVar11 = FUN_23ead7010();
                                                              if (lVar11 == 0) {
                                                                plVar15 = (longlong *)0x0;
                                                                FUN_23e915740(param_1,&local_78,
                                                                              DAT_23ee290b0);
                                                                local_98 = 0xfb;
                                                                local_120 = (longlong *)0x0;
                                                                plVar8 = local_68;
                                                                plVar10 = DAT_23ed6a4f8;
                                                                local_a8 = plStack_70;
                                                                local_a0 = local_78;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xfb;
                                                                local_120 = (longlong *)
                                                                            FUN_23e94bb80(param_1,
                                                  lVar11,DAT_23ee29340);
                                                  if (local_120 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    plVar15 = (longlong *)0x0;
                                                    local_98 = 0xfb;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar16 = (longlong *)
                                                              FUN_23e8bc2f0(local_120,DAT_23ee28fe0)
                                                    ;
                                                    plVar8 = DAT_23ee292e8;
                                                    if (plVar16 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      plVar15 = (longlong *)0x0;
                                                      local_98 = 0xfc;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar10 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),3);
                                                      *plVar8 = *plVar8 + 1;
                                                      plVar10[3] = (longlong)plVar8;
                                                      lVar11 = FUN_23ead6ec0();
                                                      if (lVar11 == 0) {
                                                        FUN_23e915740(param_1,&local_78,
                                                                      DAT_23ee29100);
                                                        local_a0 = local_78;
                                                        local_a8 = plStack_70;
                                                        plVar8 = local_68;
                                                      }
                                                      else {
                                                        lVar11 = FUN_23e94f9d0(param_1,lVar11,
                                                                               DAT_23ed6cd28);
                                                        if (lVar11 != 0) {
                                                          plVar10[4] = lVar11;
                                                          plVar8 = DAT_23ee292f0;
                                                          *DAT_23ee292f0 = *DAT_23ee292f0 + 1;
                                                          plVar10[5] = (longlong)plVar8;
                                                          plVar8 = (longlong *)
                                                                   PyUnicode_Join(DAT_23ed6cd28,
                                                                                  plVar10);
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_98 = 0xfc;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *plVar16 = *plVar16 + -1;
                                                            plVar15 = (longlong *)0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                            if (*plVar16 == 0) {
                                                              FUN_23a334bc0(plVar16);
                                                              local_98 = 0xfc;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xfc;
                                                            plVar15 = (longlong *)
                                                                      FUN_23e914090(param_1,plVar16,
                                                                                    plVar8);
                                                            *plVar16 = *plVar16 + -1;
                                                            if (*plVar16 == 0) {
                                                              FUN_23a334bc0(plVar16);
                                                            }
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            if (plVar15 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              plVar15 = (longlong *)0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              local_98 = 0xfc;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              *plVar15 = *plVar15 + -1;
                                                              if (*plVar15 == 0) {
                                                                FUN_23a334bc0(plVar15);
                                                              }
                                                              lVar11 = FUN_23ead6d70();
                                                              if (lVar11 == 0) {
                                                                FUN_23e915740(param_1,&local_78,
                                                                              DAT_23ee29258);
                                                                local_98 = 0xfd;
                                                                plVar15 = (longlong *)0x0;
                                                                plVar8 = local_68;
                                                                plVar10 = DAT_23ed6a4f8;
                                                                local_a8 = plStack_70;
                                                                local_a0 = local_78;
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xfd;
                                                                plVar15 = (longlong *)
                                                                          FUN_23e94bb80(param_1,
                                                  lVar11);
                                                  if (plVar15 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_98 = 0xfd;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    plVar10 = (longlong *)
                                                              FUN_23e8bc2f0(plVar15,DAT_23ee28fe0);
                                                    plVar8 = DAT_23ee29300;
                                                    if (plVar10 == (longlong *)0x0) {
                                                      local_a0 = *(longlong **)(param_1 + 0x60);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      local_98 = 0xfe;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_a8 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar10 = DAT_23ed6a4f8;
                                                    }
                                                    else {
                                                      plVar16 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),3);
                                                      *plVar8 = *plVar8 + 1;
                                                      plVar16[3] = (longlong)plVar8;
                                                      lVar11 = FUN_23ead6c20();
                                                      if (lVar11 == 0) {
                                                        FUN_23e915740(param_1,&local_78,
                                                                      DAT_23ee29038);
                                                        local_a0 = local_78;
                                                        local_a8 = plStack_70;
                                                        plVar8 = local_68;
                                                      }
                                                      else {
                                                        lVar11 = FUN_23e94f9d0(param_1,lVar11,
                                                                               DAT_23ed6cd28);
                                                        if (lVar11 != 0) {
                                                          plVar16[4] = lVar11;
                                                          plVar8 = DAT_23ee29308;
                                                          *DAT_23ee29308 = *DAT_23ee29308 + 1;
                                                          plVar16[5] = (longlong)plVar8;
                                                          plVar8 = (longlong *)
                                                                   PyUnicode_Join(DAT_23ed6cd28,
                                                                                  plVar16);
                                                          *plVar16 = *plVar16 + -1;
                                                          if (*plVar16 == 0) {
                                                            FUN_23a334bc0(plVar16);
                                                          }
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *plVar10 = *plVar10 + -1;
                                                            if (*plVar10 == 0) {
                                                              FUN_23a334bc0(plVar10);
                                                            }
                                                            local_98 = 0xfe;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xfe;
                                                            plVar16 = (longlong *)
                                                                      FUN_23e914090(param_1,plVar10)
                                                            ;
                                                            *plVar10 = *plVar10 + -1;
                                                            if (*plVar10 == 0) {
                                                              FUN_23a334bc0(plVar10);
                                                            }
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            if (plVar16 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              local_98 = 0xfe;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              *plVar16 = *plVar16 + -1;
                                                              if (*plVar16 == 0) {
                                                                FUN_23a334bc0(plVar16);
                                                              }
                                                              plVar16 = (longlong *)
                                                                        FUN_23e8bc2f0(plVar15,
                                                  DAT_23ee29310);
                                                  if (plVar16 == (longlong *)0x0) {
                                                    local_a0 = *(longlong **)(param_1 + 0x60);
                                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                                    local_98 = 0x10d;
                                                    local_a8 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    lVar11 = FUN_23ead7940();
                                                    if (lVar11 == 0) {
                                                      FUN_23e915740(param_1,&local_78,DAT_23ee28f90)
                                                      ;
                                                      local_a8 = plStack_70;
                                                      local_a0 = local_78;
                                                      local_98 = 0x10d;
                                                      *plVar16 = *plVar16 + -1;
                                                      plVar8 = local_68;
                                                      plVar10 = DAT_23ed6a4f8;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                        local_98 = 0x10d;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                    }
                                                    else {
                                                      plVar8 = (longlong *)
                                                               FUN_23e8bc2f0(lVar11,DAT_23ee29318);
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_98 = 0x10d;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *plVar16 = *plVar16 + -1;
                                                        plVar10 = DAT_23ed6a4f8;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                          local_98 = 0x10d;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                      }
                                                      else {
                                                        plVar10 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar8,DAT_23ee29320
                                                                               );
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar10 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          local_98 = 0x10d;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *plVar16 = *plVar16 + -1;
                                                          plVar10 = DAT_23ed6a4f8;
                                                          if (*plVar16 == 0) {
                                                            FUN_23a334bc0(plVar16);
                                                            local_98 = 0x10d;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0x10d;
                                                          plVar8 = (longlong *)
                                                                   FUN_23e914090(param_1,plVar16);
                                                          *plVar16 = *plVar16 + -1;
                                                          if (*plVar16 == 0) {
                                                            FUN_23a334bc0(plVar16);
                                                          }
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_98 = 0x10d;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            plVar8 = (longlong *)
                                                                     FUN_23e8bc2f0(plVar15,
                                                  DAT_23ee29278);
                                                  uVar3 = DAT_23ee29f70;
                                                  uVar2 = DAT_23ee29330;
                                                  if (plVar8 != (longlong *)0x0) {
                                                    *plVar18 = *plVar18 + 1;
                                                    local_78 = plVar18;
                                                    plVar10 = (longlong *)
                                                              FUN_23e93e1e0(FUN_23c616ed0,
                                                                            DAT_23ee29328,uVar2,
                                                                            DAT_23ee29f48,0,0,uVar3,
                                                                            0,&local_78,1);
                                                    *(undefined4 *)(plVar7 + 5) = 0x10e;
                                                    plVar16 = (longlong *)
                                                              FUN_23e915840(param_1,plVar8,
                                                                            DAT_23ee291f8,plVar10);
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    if (plVar16 != (longlong *)0x0) {
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0x10f;
                                                      plVar8 = (longlong *)
                                                               FUN_23e915840(param_1,plVar13,
                                                                             DAT_23ee290e8,local_120
                                                                            );
                                                      if (plVar8 == (longlong *)0x0) {
                                                        local_a0 = *(longlong **)(param_1 + 0x60);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        local_98 = 0x10f;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_a8 = *(longlong **)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar10 = DAT_23ed6a4f8;
                                                      }
                                                      else {
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *(undefined4 *)(plVar7 + 5) = 0x110;
                                                        plVar8 = (longlong *)
                                                                 FUN_23e915840(param_1,plVar13,
                                                                               DAT_23ee290e8,plVar15
                                                                              );
                                                        if (plVar8 == (longlong *)0x0) {
                                                          local_a0 = *(longlong **)(param_1 + 0x60);
                                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_98 = 0x110;
                                                          local_a8 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plVar10 = DAT_23ed6a4f8;
                                                        }
                                                        else {
                                                          *plVar8 = *plVar8 + -1;
                                                          if (*plVar8 == 0) {
                                                            FUN_23a334bc0(plVar8);
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0x111;
                                                          plVar8 = (longlong *)
                                                                   FUN_23e91bfe0(param_1,plVar13,
                                                                                 DAT_23ee29338);
                                                          if (plVar8 == (longlong *)0x0) {
                                                            local_a0 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                                            local_98 = 0x111;
                                                            local_a8 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            plVar10 = DAT_23ed6a4f8;
                                                          }
                                                          else {
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            *(undefined4 *)(plVar7 + 5) = 0x112;
                                                            plVar8 = (longlong *)
                                                                     FUN_23e915840(param_1,plVar12,
                                                                                   DAT_23ee292b0,
                                                                                   plVar13);
                                                            if (plVar8 == (longlong *)0x0) {
                                                              local_a0 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                              plVar8 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                              local_98 = 0x112;
                                                              local_a8 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plVar10 = DAT_23ed6a4f8;
                                                            }
                                                            else {
                                                              *plVar8 = *plVar8 + -1;
                                                              if (*plVar8 == 0) {
                                                                FUN_23a334bc0(plVar8);
                                                              }
                                                              *(undefined4 *)(plVar7 + 5) = 0x114;
                                                              plVar8 = (longlong *)
                                                                       FUN_23e915840(param_1,plVar9,
                                                                                     DAT_23ee290e8,
                                                                                     local_118);
                                                              if (plVar8 == (longlong *)0x0) {
                                                                local_a0 = *(longlong **)
                                                                            (param_1 + 0x60);
                                                                plVar8 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                                local_98 = 0x114;
                                                                local_a8 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                plVar10 = DAT_23ed6a4f8;
                                                              }
                                                              else {
                                                                *plVar8 = *plVar8 + -1;
                                                                if (*plVar8 == 0) {
                                                                  FUN_23a334bc0(plVar8);
                                                                }
                                                                lVar11 = FUN_23ead6ad0();
                                                                plVar8 = DAT_23ee29360;
                                                                if (lVar11 == 0) {
                                                                  FUN_23e915740(param_1,&local_78,
                                                                                DAT_23ee29350);
                                                                  local_a0 = local_78;
                                                                  local_a8 = plStack_70;
                                                                }
                                                                else {
                                                                  *plVar18 = *plVar18 + 1;
                                                                  local_80 = plVar18;
                                                                  plVar10 = (longlong *)
                                                                            FUN_23e93e1e0(
                                                  FUN_23c6173b0,DAT_23ee29328,DAT_23ee29330,
                                                  DAT_23ee29f50,0,0,DAT_23ee29f70,0,&local_80,1);
                                                  *(undefined4 *)(plVar7 + 5) = 0x117;
                                                  local_78 = plVar8;
                                                  plStack_70 = plVar10;
                                                  plVar8 = (longlong *)
                                                           FUN_23e954670(param_1,lVar11,
                                                                         DAT_23ee29358,&local_78);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  if (plVar8 != (longlong *)0x0) {
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                                    pcVar4 = _Py_NoneStruct_exref;
                                                    *(longlong *)_Py_NoneStruct_exref =
                                                         *(longlong *)_Py_NoneStruct_exref + 1;
                                                    *plVar18 = *plVar18 + -1;
                                                    if (*plVar18 == 0) {
                                                      FUN_23a334bc0(plVar18);
                                                    }
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    lVar11 = *local_d0;
                                                    *local_d0 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_d0);
                                                    }
                                                    lVar11 = *local_e0;
                                                    *local_e0 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_e0);
                                                    }
                                                    lVar11 = *local_b8;
                                                    *local_b8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_b8);
                                                    }
                                                    lVar11 = *local_c8;
                                                    *local_c8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_c8);
                                                    }
                                                    lVar11 = *local_c0;
                                                    *local_c0 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_c0);
                                                    }
                                                    lVar11 = *local_b0;
                                                    *local_b0 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_b0);
                                                    }
                                                    lVar11 = *local_d8;
                                                    *local_d8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_d8);
                                                    }
                                                    lVar11 = *local_e8;
                                                    *local_e8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_e8);
                                                    }
                                                    lVar11 = *local_f0;
                                                    *local_f0 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_f0);
                                                    }
                                                    lVar11 = *local_118;
                                                    *local_118 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_118);
                                                    }
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                    lVar11 = *local_f8;
                                                    *local_f8 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_f8);
                                                    }
                                                    lVar11 = *local_100;
                                                    *local_100 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_100);
                                                    }
                                                    lVar11 = *local_108;
                                                    *local_108 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_108);
                                                    }
                                                    lVar11 = *local_110;
                                                    *local_110 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_110);
                                                    }
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    lVar11 = *local_120;
                                                    *local_120 = lVar11 + -1;
                                                    if (lVar11 + -1 == 0) {
                                                      FUN_23a334bc0(local_120);
                                                    }
                                                    *plVar15 = *plVar15 + -1;
                                                    if (*plVar15 != 0) {
                                                      return pcVar4;
                                                    }
                                                    FUN_23a334bc0(plVar15);
                                                    return pcVar4;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  local_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  local_98 = 0x117;
                                                  plVar8 = local_68;
                                                  plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  local_98 = 0x10e;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  *plVar16 = *plVar16 + -1;
                                                  local_98 = 0x101;
                                                  plVar10 = DAT_23ed6a4f8;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                    local_98 = 0x101;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    FUN_23a334bc0(plVar10);
                                                    local_98 = 0xfc;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0xfc;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  plVar15 = (longlong *)0x0;
                                                  local_98 = 0xf2;
                                                  plVar13 = (longlong *)0x0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_120 = (longlong *)0x0;
                                                  plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar15 = *plVar15 + -1;
                                                  if (*plVar15 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    FUN_23a334bc0();
                                                    local_98 = 0xe5;
                                                    local_120 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0xe5;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_120 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    plVar13 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    FUN_23a334bc0();
                                                    local_98 = 0xe0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0xe0;
                                                    plVar15 = (longlong *)0x0;
                                                    local_120 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  lVar11 = *plVar13;
                                                  *plVar13 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    FUN_23a334bc0(plVar10);
                                                    local_98 = 0xd9;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0xd9;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_120 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  lVar11 = *plVar10;
                                                  *plVar10 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar12 = *plVar12 + -1;
                                                  if (*plVar12 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23a334bc0();
                                                    local_120 = (longlong *)0x0;
                                                    local_98 = 0xa4;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0xa4;
                                                    plVar15 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_120 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23a334bc0(plVar10);
                                                    local_120 = (longlong *)0x0;
                                                    local_98 = 0xa0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0xa0;
                                                    local_120 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23a334bc0();
                                                    local_120 = (longlong *)0x0;
                                                    local_98 = 0x8d;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0x8d;
                                                    local_120 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  lVar11 = *plVar12;
                                                  *plVar12 = lVar11 + -1;
                                                  if (lVar11 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    plVar13 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    FUN_23a334bc0();
                                                    local_120 = (longlong *)0x0;
                                                    local_98 = 0x83;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    local_e0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  else {
                                                    local_98 = 0x83;
                                                    local_120 = (longlong *)0x0;
                                                    plVar15 = (longlong *)0x0;
                                                    plVar13 = (longlong *)0x0;
                                                    plVar12 = (longlong *)0x0;
                                                    local_110 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_f8 = (longlong *)0x0;
                                                    local_118 = (longlong *)0x0;
                                                    local_f0 = (longlong *)0x0;
                                                    local_e8 = (longlong *)0x0;
                                                    local_d8 = (longlong *)0x0;
                                                    local_b0 = (longlong *)0x0;
                                                    local_c0 = (longlong *)0x0;
                                                    local_c8 = (longlong *)0x0;
                                                    local_b8 = (longlong *)0x0;
                                                    local_e0 = (longlong *)0x0;
                                                    plVar10 = DAT_23ed6a4f8;
                                                  }
                                                  goto joined_r0x00023c60e893;
                                                  }
                                                  local_a0 = *(longlong **)(param_1 + 0x60);
                                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                                  local_98 = 0x73;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_a8 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar6 = *(int *)(lVar11 + 0xc);
    if (*(int *)(lVar11 + 0xc) == 0) {
      *(int *)(lVar11 + 0xc) = DAT_23ec12b2c;
      iVar6 = DAT_23ec12b2c;
      DAT_23ec12b2c = DAT_23ec12b2c + 1;
    }
    if (DAT_23ec12b24 != iVar6) {
      DAT_23ec12b24 = iVar6;
      DAT_23ee29f28 = FUN_23e8cbd60(lVar11,DAT_23ee28ff0,*(undefined8 *)(DAT_23ee28ff0 + 0x18));
    }
    if (-1 < DAT_23ee29f28) {
      lVar1 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
      plVar8 = *(longlong **)(lVar1 + 8 + DAT_23ee29f28 * 0x10);
      if (plVar8 != (longlong *)0x0) goto LAB_23c60a845;
      DAT_23ee29f28 = FUN_23e8cbd60(lVar11,DAT_23ee28ff0,*(undefined8 *)(DAT_23ee28ff0 + 0x18));
      if (-1 < DAT_23ee29f28) {
        plVar8 = *(longlong **)(lVar1 + 8 + DAT_23ee29f28 * 0x10);
        goto LAB_23c60f388;
      }
    }
LAB_23c60e719:
    puVar17 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ee28ff0);
    if ((puVar17 != (undefined8 *)0x0) && (plVar8 = (longlong *)*puVar17, plVar8 != (longlong *)0x0)
       ) goto LAB_23c60a845;
    FUN_23e915740(param_1,&local_78,DAT_23ee28ff0);
    local_98 = 0x35;
    local_a0 = local_78;
    local_a8 = plStack_70;
    plVar8 = local_68;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    plVar13 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    (**(code **)(plVar10[1] + 0x30))(plVar10);
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    plVar10 = DAT_23ed6a4f8;
  }
  else {
    local_120 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    plVar10 = DAT_23ed6a4f8;
  }
joined_r0x00023c60e893:
  DAT_23ed6a4f8 = plVar10;
  if (plVar8 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar11 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = local_98;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar1 = plVar10[-1];
    puVar17 = *(undefined8 **)(lVar11 + 8);
    *puVar17 = plVar10 + -2;
    plVar10[-2] = lVar11;
    plVar10[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar11 + 8) = plVar10 + -2;
    plVar16 = plVar10;
  }
  else {
    plVar16 = plVar8;
    if ((longlong *)plVar8[3] != plVar7) {
      if (plVar10 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar10[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      *(undefined4 *)((longlong)plVar10 + 0x24) = local_98;
      pcVar4 = _PyRuntime_exref;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar10[-1];
      puVar17 = *(undefined8 **)(lVar11 + 8);
      *puVar17 = plVar10 + -2;
      plVar10[-2] = lVar11;
      plVar10[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar17;
      lVar1 = *plVar8;
      *(longlong **)(lVar11 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar8;
      plVar16 = plVar10;
      if (lVar1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar7,"cooooooooooooooooooo",plVar18,plVar9,local_d0,local_e0,local_b8,local_c8,
                local_c0,local_b0,local_d8,local_e8,local_f0,local_118,plVar12,local_f8,local_100,
                local_108,local_110,plVar13,local_120,plVar15);
  if (DAT_23ee29f60 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    DAT_23ee29f60 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar11 + 0x28);
  plVar8 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar18 = *plVar18 + -1;
  if (*plVar18 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((local_d0 != (longlong *)0x0) &&
     (lVar11 = *local_d0, *local_d0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_d0[1] + 0x30))(local_d0);
  }
  if ((local_e0 != (longlong *)0x0) &&
     (lVar11 = *local_e0, *local_e0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar11 = *local_b8, *local_b8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  if ((local_c8 != (longlong *)0x0) &&
     (lVar11 = *local_c8, *local_c8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_c8[1] + 0x30))();
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar11 = *local_c0, *local_c0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((local_b0 != (longlong *)0x0) &&
     (lVar11 = *local_b0, *local_b0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_b0[1] + 0x30))(local_b0);
  }
  if ((local_d8 != (longlong *)0x0) &&
     (lVar11 = *local_d8, *local_d8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_d8[1] + 0x30))(local_d8);
  }
  if ((local_e8 != (longlong *)0x0) &&
     (lVar11 = *local_e8, *local_e8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  if ((local_f0 != (longlong *)0x0) &&
     (lVar11 = *local_f0, *local_f0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_f0[1] + 0x30))();
  }
  if ((local_118 != (longlong *)0x0) &&
     (lVar11 = *local_118, *local_118 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_118[1] + 0x30))(local_118);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar11 = *local_110, *local_110 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_120 != (longlong *)0x0) &&
     (lVar11 = *local_120, *local_120 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_120[1] + 0x30))(local_120);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  FUN_23a33aa70(param_1,local_a0,local_a8,plVar16);
  return (code *)0x0;
}
