/* ===== 23e308230 ui.fish_settings_dialog:c1169 ===== */
/* ghidra_name=FUN_23e308230 entry=23e308230 size=12131 */

code * FUN_23e308230(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  code *pcVar19;
  longlong lVar20;
  longlong *plVar21;
  longlong lVar22;
  longlong lVar23;
  undefined8 uVar24;
  undefined4 uVar25;
  bool bVar26;
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_d8;
  longlong *local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_a8;
  longlong *local_a0;
  undefined1 local_98 [16];
  longlong *local_88 [2];
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  undefined8 uStack_60;
  
  plVar8 = DAT_23eeb0708;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_88[0] = (longlong *)0x0;
  local_98 = (undefined1  [16])0x0;
  if (DAT_23eeb0708 == (longlong *)0x0) {
LAB_23e30829b:
    DAT_23eeb0708 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb07a8,DAT_23eeb0770,0x60);
  }
  else {
    lVar9 = *DAT_23eeb0708;
    if (1 < lVar9) {
      *DAT_23eeb0708 = lVar9 + -1;
      goto LAB_23e30829b;
    }
    if (DAT_23eeb0708[2] != 0) {
      *DAT_23eeb0708 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e30829b;
    }
  }
  plVar3 = DAT_23eeb0708;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eeb0708 + 9;
  lVar23 = *(longlong *)(lVar9 + 8);
  DAT_23eeb0708[0xf] = lVar23;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar23 != 0) &&
     (((*(char *)(lVar23 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar23 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar23 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar23 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar23 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  if ((DAT_23ed77850 == 0) && (DAT_23ed77850 = PyImport_ImportModule("ntpath"), DAT_23ed77850 == 0))
  {
LAB_23e3092c3:
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_NTPATH",
                  "\"Unexpected failure of hard import of \'ntpath\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(DAT_23ed77850,DAT_23eeaf5a0);
  if (plVar8 == (longlong *)0x0) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88[0] = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar25 = 0xbc;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
  }
  else {
    lVar9 = FUN_23e8f9a00();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_98,DAT_23ed6cd80);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
LAB_23e30940c:
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      plVar10 = (longlong *)0x0;
    }
    else {
      plVar10 = (longlong *)FUN_23e936ef0(param_1,lVar9);
      if (plVar10 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e936ef0(param_1,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        uVar24 = DAT_23eeaf5b8;
        plVar14 = DAT_23eeaf5b0;
        plVar10 = DAT_23eeaf5a8;
        if (plVar11 == (longlong *)0x0) {
          local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar8 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          uVar25 = 0xbc;
          plVar11 = (longlong *)0x0;
          goto LAB_23e308bfd;
        }
        *(undefined4 *)(plVar3 + 5) = 0xbc;
        plStack_70 = plVar10;
        local_68 = plVar14;
        uStack_60 = uVar24;
        local_78 = plVar11;
        plVar10 = (longlong *)FUN_23e9583d0(param_1,plVar8,&local_78);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        lVar9 = DAT_23eeaf5c0;
        if (plVar10 == (longlong *)0x0) {
          local_88[0] = *(longlong **)(param_1 + 0x70);
          local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e309259;
        }
        lVar23 = *(longlong *)(DAT_23eeaf5c0 + 0x10);
        plVar8 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),lVar23);
        if ((plVar8 != (longlong *)0x0) && (0 < lVar23)) {
          lVar9 = *(longlong *)(lVar9 + 0x18);
          lVar22 = plVar8[3];
          lVar12 = 0;
          do {
            plVar11 = *(longlong **)(lVar9 + lVar12 * 8);
            *plVar11 = *plVar11 + 1;
            *(longlong **)(lVar22 + lVar12 * 8) = plVar11;
            lVar12 = lVar12 + 1;
          } while (lVar23 != lVar12);
        }
        plVar11 = DAT_23eeaf5c8;
        if (*(code **)(DAT_23eeaf5c8[1] + 0xd8) == (code *)0x0) {
          plVar13 = (longlong *)FUN_23a33a530(PySeqIter_Type_exref);
          plVar13[2] = 0;
          *plVar11 = *plVar11 + 1;
          plVar13[3] = (longlong)plVar11;
          lVar9 = *(longlong *)
                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar23 = plVar13[-1];
          plVar11 = *(longlong **)(lVar9 + 8);
          *plVar11 = (longlong)(plVar13 + -2);
          plVar13[-2] = lVar9;
          plVar13[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)plVar11;
          *(longlong **)(lVar9 + 8) = plVar13 + -2;
        }
        else {
          plVar13 = (longlong *)(**(code **)(DAT_23eeaf5c8[1] + 0xd8))(DAT_23eeaf5c8);
        }
        plVar11 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
        if ((plVar11 == (longlong *)0x0) &&
           (plVar11 = (longlong *)FUN_23a3c1b70(param_1,local_98,0,2), plVar11 == (longlong *)0x0))
        {
          plVar14 = (longlong *)0x0;
        }
        else {
          plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
          if (((plVar14 != (longlong *)0x0) ||
              (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,2), plVar14 != (longlong *)0x0
              )) && (cVar6 = FUN_23a3884a0(param_1,local_98,plVar13,2), cVar6 != '\0')) {
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            plVar13 = (longlong *)FUN_23ebf7180();
            if (plVar13 == (longlong *)0x0) {
              local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_88[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar25 = 0xe5;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e308bfd;
            }
            if (plVar1 == (longlong *)0x0) {
              local_d0 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
              if (local_d0 != (longlong *)0x0) {
                plVar16 = (longlong *)FUN_23a388310(local_d0);
                if (plVar16 == (longlong *)0x0) {
                  local_c8 = (longlong *)0x0;
                  local_c0 = (longlong *)0x0;
                  local_d8 = (longlong *)0x0;
                  local_a0 = (longlong *)0x0;
                  local_a8 = (longlong *)0x0;
                  local_f0 = plVar11;
LAB_23e30a456:
                  local_e0 = local_c8;
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar19 = *(code **)(param_1 + 0x60);
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  local_e8 = local_c0;
                  local_f8 = local_a8;
                  plVar11 = local_f0;
                  local_f0 = local_d8;
                }
                else {
                  plVar17 = (longlong *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                  if ((plVar17 == (longlong *)0x0) &&
                     (plVar17 = (longlong *)FUN_23a3c1b70(param_1,local_98),
                     plVar17 == (longlong *)0x0)) {
                    local_c8 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_a8 = (longlong *)0x0;
                    local_a0 = plVar17;
LAB_23e3098aa:
                    plVar18 = (longlong *)0x0;
                    plVar17 = (longlong *)0x0;
                    local_e0 = local_c8;
                    local_e8 = local_c0;
                    local_f0 = local_d8;
                    local_f8 = local_a8;
                    plVar21 = (longlong *)0x0;
                  }
                  else {
                    local_f8 = (longlong *)(**(code **)(plVar16[1] + 0xe0))();
                    if ((local_f8 == (longlong *)0x0) &&
                       (local_f8 = (longlong *)FUN_23a3c1b70(param_1,local_98,1),
                       local_f8 == (longlong *)0x0)) {
                      local_c8 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_a8 = (longlong *)0x0;
                      local_a0 = (longlong *)0x0;
LAB_23e309b5d:
                      plVar18 = (longlong *)0x0;
                      local_e0 = local_c8;
                      local_e8 = local_c0;
                      local_f0 = local_d8;
                      local_f8 = local_a8;
                      plVar21 = (longlong *)0x0;
                    }
                    else {
                      local_f0 = (longlong *)(**(code **)(plVar16[1] + 0xe0))();
                      if ((local_f0 == (longlong *)0x0) &&
                         (local_f0 = (longlong *)FUN_23a3c1b70(param_1,local_98,2,3),
                         local_f0 == (longlong *)0x0)) {
                        local_c8 = (longlong *)0x0;
                        local_c0 = (longlong *)0x0;
                        local_d8 = (longlong *)0x0;
                        local_a8 = (longlong *)0x0;
                        local_a0 = (longlong *)0x0;
LAB_23e309c2d:
                        plVar18 = local_f8;
                        local_e0 = local_c8;
                        local_e8 = local_c0;
                        local_f0 = local_d8;
                        local_f8 = local_a8;
                        plVar21 = (longlong *)0x0;
                      }
                      else {
                        cVar6 = FUN_23a3884a0(param_1,local_98,plVar16);
                        lVar9 = *plVar16;
                        plVar18 = local_f0;
                        if (cVar6 != '\0') {
                          *plVar16 = lVar9 + -1;
                          if (lVar9 + -1 == 0) {
                            (**(code **)(plVar16[1] + 0x30))();
                          }
                          if (*plVar17 == 0) {
                            (**(code **)(plVar17[1] + 0x30))(plVar17);
                          }
                          if (*local_f8 == 0) {
                            (**(code **)(local_f8[1] + 0x30))();
                          }
                          if (*local_f0 == 0) {
                            (**(code **)(local_f0[1] + 0x30))();
                          }
                          if ((DAT_23ed77850 == 0) &&
                             (DAT_23ed77850 = PyImport_ImportModule("ntpath"), DAT_23ed77850 == 0))
                          {
                            DAT_23ed77850 = 0;
                            goto LAB_23e3092c3;
                          }
                          plVar15 = (longlong *)FUN_23e8bc2f0(DAT_23ed77850,DAT_23eeaf5a0);
                          if (plVar15 == (longlong *)0x0) {
                            local_c8 = (longlong *)0x0;
                            local_c0 = (longlong *)0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0xe6;
                            plStack_70 = local_f0;
                            local_78 = plVar10;
                            local_e8 = (longlong *)FUN_23e94ed00(param_1,plVar15,&local_78);
                            lVar9 = *plVar15;
                            *plVar15 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                            }
                            if (local_e8 != (longlong *)0x0) {
                              lVar9 = *(longlong *)(DAT_23eeaf268 + 0x20);
                              if (*(char *)(lVar9 + 10) == '\0') {
                                local_c8 = (longlong *)FUN_23a37a020(DAT_23eeaf268,DAT_23eeaf5d8);
                                if (local_c8 == (longlong *)0x0) goto LAB_23e30ad8c;
                                local_c8 = (longlong *)*local_c8;
LAB_23e30ad7d:
                                if (local_c8 == (longlong *)0x0) goto LAB_23e30ad8c;
LAB_23e30a306:
                                *(undefined4 *)(plVar3 + 5) = 0xe9;
                                plStack_70 = local_f8;
                                local_78 = plVar17;
                                local_68 = local_e8;
                                local_e0 = (longlong *)FUN_23e956150(param_1,local_c8,&local_78);
                                if (local_e0 == (longlong *)0x0) {
                                  local_c8 = (longlong *)0x0;
LAB_23e30a931:
                                  local_f0 = plVar18;
                                  pcVar19 = *(code **)(param_1 + 0x60);
                                  plVar15 = *(longlong **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  uVar25 = 0xe9;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_e0 = local_c8;
                                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                                }
                                else {
                                  local_98._8_8_ =
                                       PyUnicode_FromFormat
                                                 ("cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,DAT_23eeaf5e0);
                                  local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                                  *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
                                  local_88[0] = (longlong *)0x0;
                                  if ((code *)local_98._0_8_ != _Py_NoneStruct_exref) {
                                    FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
                                  }
                                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
                                  uVar25 = 0xea;
                                  plVar15 = local_88[0];
                                  pcVar19 = (code *)local_98._0_8_;
                                  uVar24 = local_98._8_8_;
                                }
                              }
                              else {
                                iVar7 = *(int *)(lVar9 + 0xc);
                                if (*(int *)(lVar9 + 0xc) == 0) {
                                  *(int *)(lVar9 + 0xc) = DAT_23ec14f00;
                                  iVar7 = DAT_23ec14f00;
                                  DAT_23ec14f00 = DAT_23ec14f00 + 1;
                                }
                                if (DAT_23ec14ee8 != iVar7) {
                                  DAT_23ec14ee8 = iVar7;
                                  DAT_23eeb0700 =
                                       FUN_23e8cbd60(lVar9,DAT_23eeaf5d8,
                                                     *(undefined8 *)(DAT_23eeaf5d8 + 0x18));
                                }
                                if (-1 < DAT_23eeb0700) {
                                  lVar23 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                                  local_c8 = *(longlong **)(lVar23 + 8 + DAT_23eeb0700 * 0x10);
                                  if (local_c8 != (longlong *)0x0) goto LAB_23e30a306;
                                  DAT_23eeb0700 =
                                       FUN_23e8cbd60(lVar9,DAT_23eeaf5d8,
                                                     *(undefined8 *)(DAT_23eeaf5d8 + 0x18));
                                  if (-1 < DAT_23eeb0700) {
                                    local_c8 = *(longlong **)(lVar23 + 8 + DAT_23eeb0700 * 0x10);
                                    goto LAB_23e30ad7d;
                                  }
                                }
LAB_23e30ad8c:
                                local_c8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeaf5d8);
                                if (local_c8 != (longlong *)0x0) {
                                  local_c8 = (longlong *)*local_c8;
                                  if (local_c8 != (longlong *)0x0) goto LAB_23e30a306;
                                  local_c8 = (longlong *)0x0;
                                }
LAB_23e309010:
                                local_f0 = plVar18;
                                local_e0 = local_c8;
                                FUN_23e915740(param_1,local_98,DAT_23eeaf5d8);
                                uVar25 = 0xe9;
                                plVar15 = local_88[0];
                                pcVar19 = (code *)local_98._0_8_;
                                uVar24 = local_98._8_8_;
                              }
                              goto LAB_23e309066;
                            }
                            local_c8 = (longlong *)0x0;
                            local_c0 = (longlong *)0x0;
                          }
LAB_23e309ef5:
                          local_f0 = plVar18;
                          pcVar19 = *(code **)(param_1 + 0x60);
                          plVar15 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          uVar25 = 0xe6;
                          local_e0 = local_c8;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          local_e8 = local_c0;
                          uVar24 = *(undefined8 *)(param_1 + 0x68);
                          goto LAB_23e309066;
                        }
                        local_c8 = (longlong *)0x0;
                        local_c0 = (longlong *)0x0;
                        local_d8 = (longlong *)0x0;
                        local_a8 = (longlong *)0x0;
                        local_a0 = (longlong *)0x0;
LAB_23e30a7d7:
                        local_f0 = plVar18;
                        local_e0 = local_c8;
                        local_e8 = local_c0;
                        plVar21 = local_f0;
                        plVar18 = local_f8;
                        local_f8 = local_a8;
                        local_f0 = local_d8;
                      }
                    }
                  }
                  plVar15 = local_88[0];
                  pcVar19 = (code *)local_98._0_8_;
                  uVar24 = local_98._8_8_;
                  local_88[0] = (longlong *)0x0;
                  local_98 = (undefined1  [16])0x0;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  local_88[0] = (longlong *)0x0;
                  local_98 = (undefined1  [16])0x0;
                  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                    (**(code **)(plVar18[1] + 0x30))(plVar18);
                  }
                  if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                    (**(code **)(plVar21[1] + 0x30))(plVar21);
                  }
                }
                uVar25 = 0xe5;
                plVar17 = local_a0;
                goto LAB_23e309066;
              }
              local_d0 = (longlong *)0x0;
              local_c8 = (longlong *)0x0;
              local_c0 = (longlong *)0x0;
              local_d8 = (longlong *)0x0;
              local_a8 = (longlong *)0x0;
              local_a0 = (longlong *)0x0;
LAB_23e30a4fc:
              cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
              if (cVar6 != '\0') {
                lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar3 = *(longlong **)(lVar9 + 0x28);
                plVar15 = (longlong *)plVar3[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
                *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                if (plVar15 != (longlong *)0x0) {
                  plVar3[2] = 0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))();
                  }
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                plVar3[0xf] = 0;
                if ((local_d0 != (longlong *)0x0) && (*local_d0 = *local_d0 + -1, *local_d0 == 0)) {
                  (**(code **)(local_d0[1] + 0x30))(local_d0);
                }
                lVar9 = *plVar13;
                *plVar13 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                pcVar19 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if ((local_a0 != (longlong *)0x0) &&
                   (lVar9 = *local_a0, *local_a0 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_a0[1] + 0x30))(local_a0);
                }
                if ((local_a8 != (longlong *)0x0) &&
                   (lVar9 = *local_a8, *local_a8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_a8[1] + 0x30))(local_a8);
                }
                if ((local_d8 != (longlong *)0x0) &&
                   (lVar9 = *local_d8, *local_d8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_d8[1] + 0x30))(local_d8);
                }
                if ((local_c0 != (longlong *)0x0) &&
                   (lVar9 = *local_c0, *local_c0 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_c0[1] + 0x30))(local_c0);
                }
                if ((local_c8 != (longlong *)0x0) &&
                   (lVar9 = *local_c8, *local_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_c8[1] + 0x30))(local_c8);
                }
                lVar9 = *plVar1;
                *plVar1 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                lVar9 = *plVar2;
                *plVar2 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                  return pcVar19;
                }
                return pcVar19;
              }
              plVar15 = *(longlong **)(param_1 + 0x70);
              pcVar19 = *(code **)(param_1 + 0x60);
              uVar24 = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_88[0] = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              local_98 = (undefined1  [16])0x0;
              if (local_d0 != (longlong *)0x0) {
                uVar25 = 0xe5;
                local_e0 = local_c8;
                local_e8 = local_c0;
                local_f0 = local_d8;
                local_f8 = local_a8;
                plVar17 = local_a0;
                goto LAB_23e309066;
              }
              local_e0 = local_c8;
              uVar25 = 0xe5;
              local_e8 = local_c0;
              local_f0 = local_d8;
              local_f8 = local_a8;
            }
            else {
              local_c8 = (longlong *)0x0;
              local_c0 = (longlong *)0x0;
              local_a0 = (longlong *)0x0;
              local_d8 = (longlong *)0x0;
              local_d0 = (longlong *)0x0;
              local_a8 = (longlong *)0x0;
              local_f0 = plVar11;
              do {
                plVar15 = (longlong *)(**(code **)(plVar13[1] + 0xe0))();
                plVar11 = local_f0;
                if (plVar15 == (longlong *)0x0) goto LAB_23e30a4fc;
                if ((local_d0 != (longlong *)0x0) && (*local_d0 = *local_d0 + -1, *local_d0 == 0)) {
                  (**(code **)(local_d0[1] + 0x30))(local_d0);
                }
                plVar16 = (longlong *)FUN_23a388310(plVar15);
                local_d0 = plVar15;
                if (plVar16 == (longlong *)0x0) goto LAB_23e30a456;
                plVar17 = (longlong *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                if ((plVar17 == (longlong *)0x0) &&
                   (plVar17 = (longlong *)FUN_23a3c1b70(param_1,local_98,0),
                   plVar17 == (longlong *)0x0)) goto LAB_23e3098aa;
                local_f8 = (longlong *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                if ((local_f8 == (longlong *)0x0) &&
                   (local_f8 = (longlong *)FUN_23a3c1b70(param_1,local_98,1),
                   local_f8 == (longlong *)0x0)) goto LAB_23e309b5d;
                plVar18 = (longlong *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                if ((plVar18 == (longlong *)0x0) &&
                   (plVar18 = (longlong *)FUN_23a3c1b70(param_1,local_98,2,3),
                   plVar18 == (longlong *)0x0)) goto LAB_23e309c2d;
                cVar6 = FUN_23a3884a0(param_1,local_98,plVar16,3);
                lVar9 = *plVar16;
                if (cVar6 == '\0') goto LAB_23e30a7d7;
                *plVar16 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                lVar9 = *plVar17;
                *plVar17 = lVar9 + 1;
                if (local_a0 != (longlong *)0x0) {
                  *local_a0 = *local_a0 + -1;
                  if (*local_a0 == 0) {
                    (**(code **)(local_a0[1] + 0x30))(local_a0);
                    lVar9 = *plVar17 + -1;
                  }
                  else {
                    lVar9 = *plVar17 + -1;
                  }
                }
                *plVar17 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                lVar9 = *local_f8;
                *local_f8 = lVar9 + 1;
                if (local_a8 != (longlong *)0x0) {
                  *local_a8 = *local_a8 + -1;
                  if (*local_a8 == 0) {
                    (**(code **)(local_a8[1] + 0x30))(local_a8);
                    lVar9 = *local_f8 + -1;
                  }
                  else {
                    lVar9 = *local_f8 + -1;
                  }
                }
                *local_f8 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(local_f8[1] + 0x30))(local_f8);
                }
                lVar9 = *plVar18;
                *plVar18 = lVar9 + 1;
                if (local_d8 != (longlong *)0x0) {
                  *local_d8 = *local_d8 + -1;
                  if (*local_d8 == 0) {
                    (**(code **)(local_d8[1] + 0x30))(local_d8);
                    lVar9 = *plVar18 + -1;
                  }
                  else {
                    lVar9 = *plVar18 + -1;
                  }
                }
                *plVar18 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                if ((DAT_23ed77850 == 0) &&
                   (DAT_23ed77850 = PyImport_ImportModule("ntpath"), DAT_23ed77850 == 0)) {
                  DAT_23ed77850 = 0;
                  goto LAB_23e3092c3;
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(DAT_23ed77850,DAT_23eeaf5a0);
                if (plVar15 == (longlong *)0x0) goto LAB_23e309ef5;
                *(undefined4 *)(plVar3 + 5) = 0xe6;
                local_78 = plVar10;
                plStack_70 = plVar18;
                local_e8 = (longlong *)FUN_23e94ed00(param_1,plVar15,&local_78);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (local_e8 == (longlong *)0x0) goto LAB_23e309ef5;
                if ((local_c0 != (longlong *)0x0) &&
                   (lVar9 = *local_c0, *local_c0 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_c0[1] + 0x30))(local_c0);
                }
                lVar9 = *(longlong *)(DAT_23eeaf268 + 0x20);
                if (*(char *)(lVar9 + 10) == '\0') {
                  plVar15 = (longlong *)FUN_23a37a020(DAT_23eeaf268,DAT_23eeaf5d8);
                  if (plVar15 == (longlong *)0x0) goto LAB_23e308fa9;
                  lVar23 = *plVar15;
LAB_23e309ca8:
                  if (lVar23 == 0) goto LAB_23e308fa9;
                }
                else {
                  iVar7 = *(int *)(lVar9 + 0xc);
                  if (*(int *)(lVar9 + 0xc) == 0) {
                    *(int *)(lVar9 + 0xc) = DAT_23ec14f00;
                    iVar7 = DAT_23ec14f00;
                    DAT_23ec14f00 = DAT_23ec14f00 + 1;
                  }
                  if (DAT_23ec14ee8 != iVar7) {
                    DAT_23ec14ee8 = iVar7;
                    DAT_23eeb0700 =
                         FUN_23e8cbd60(lVar9,DAT_23eeaf5d8,*(undefined8 *)(DAT_23eeaf5d8 + 0x18));
                  }
                  if (-1 < DAT_23eeb0700) {
                    lVar22 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                    lVar23 = *(longlong *)(lVar22 + 8 + DAT_23eeb0700 * 0x10);
                    if (lVar23 != 0) goto LAB_23e308838;
                    DAT_23eeb0700 =
                         FUN_23e8cbd60(lVar9,DAT_23eeaf5d8,*(undefined8 *)(DAT_23eeaf5d8 + 0x18));
                    if (-1 < DAT_23eeb0700) {
                      lVar23 = *(longlong *)(lVar22 + 8 + DAT_23eeb0700 * 0x10);
                      goto LAB_23e309ca8;
                    }
                  }
LAB_23e308fa9:
                  plVar15 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeaf5d8);
                  if ((plVar15 == (longlong *)0x0) || (lVar23 = *plVar15, lVar23 == 0))
                  goto LAB_23e309010;
                }
LAB_23e308838:
                *(undefined4 *)(plVar3 + 5) = 0xe9;
                local_78 = plVar17;
                plStack_70 = local_f8;
                local_68 = local_e8;
                local_e0 = (longlong *)FUN_23e956150(param_1,lVar23,&local_78);
                if (local_e0 == (longlong *)0x0) goto LAB_23e30a931;
                if ((local_c8 != (longlong *)0x0) &&
                   (lVar9 = *local_c8, *local_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(local_c8[1] + 0x30))(local_c8);
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeaf440);
                if (plVar15 == (longlong *)0x0) {
LAB_23e309f4d:
                  uVar25 = 0xea;
                  pcVar19 = *(code **)(param_1 + 0x60);
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  local_f0 = plVar18;
                  goto LAB_23e309066;
                }
                cVar6 = FUN_23a39bc50(param_1,plVar15,plVar17,local_e0);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (cVar6 == '\0') goto LAB_23e309f4d;
                uVar24 = DAT_23eeaf5e8;
                if (plVar2 == (longlong *)0x0) goto LAB_23e30a9db;
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeaf388);
                if (plVar15 == (longlong *)0x0) {
LAB_23e30a00d:
                  uVar25 = 0xec;
                  pcVar19 = *(code **)(param_1 + 0x60);
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  local_f0 = plVar18;
                  goto LAB_23e309066;
                }
                if (local_f0 == (longlong *)0x0) {
                  *plVar15 = *plVar15 + -1;
                  uVar24 = DAT_23eeaf5f0;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                    uVar24 = DAT_23eeaf5f0;
                  }
LAB_23e30a9db:
                  local_98._8_8_ =
                       PyUnicode_FromFormat
                                 ("cannot access local variable \'%U\' where it is not associated with a value"
                                  ,uVar24);
                  local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                  *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
                  local_88[0] = (longlong *)0x0;
                  if ((code *)local_98._0_8_ != _Py_NoneStruct_exref) {
                    FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
                  }
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
                  uVar25 = 0xec;
                  plVar15 = local_88[0];
                  pcVar19 = (code *)local_98._0_8_;
                  uVar24 = local_98._8_8_;
                  local_f0 = plVar18;
                  goto LAB_23e309066;
                }
                if (plVar14 == (longlong *)0x0) {
                  *plVar15 = *plVar15 + -1;
                  uVar24 = DAT_23eeaf5f8;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                    uVar24 = DAT_23eeaf5f8;
                  }
                  goto LAB_23e30a9db;
                }
                *(undefined4 *)(plVar3 + 5) = 0xec;
                plStack_70 = local_f0;
                local_78 = local_e0;
                local_68 = plVar14;
                plVar16 = (longlong *)FUN_23e956150(param_1,plVar15,&local_78);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e30a00d;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                local_78 = plVar14;
                if ((code *)plVar14[1] != PyLong_Type_exref) {
                  cVar6 = FUN_23e8c7160(&local_78);
                  plVar15 = local_78;
                  if (cVar6 != '\0') goto LAB_23e3089ee;
LAB_23e30a871:
                  uVar25 = 0xee;
                  pcVar19 = *(code **)(param_1 + 0x60);
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  local_f0 = plVar18;
                  goto LAB_23e309066;
                }
                lVar9 = plVar14[2];
                lVar23 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
                lVar22 = *plVar14;
                if (lVar9 < 0) {
                  lVar20 = -lVar9;
                  lVar12 = lVar23;
                  if (lVar9 == -1 || lVar20 < 1) {
                    if (lVar23 < 0) {
                      lVar12 = -lVar23;
                      if (lVar23 == -1 || lVar12 < 1) {
                        iVar7 = -(int)plVar14[3];
                        goto LAB_23e30abdd;
                      }
                      if (lVar22 == 1) goto LAB_23e30ad17;
LAB_23e30a0b2:
                      plVar15 = (longlong *)
                                FUN_23e8be550(plVar14 + 3,lVar20,DAT_23ed6ccf8 + 0x18,lVar12);
                      plVar15[2] = -plVar15[2];
                      goto LAB_23e3093ba;
                    }
                    if (lVar23 < 2) {
                      iVar7 = -(int)plVar14[3];
                      goto LAB_23e30a842;
                    }
                    if (lVar22 != 1) goto LAB_23e309823;
                  }
                  else {
                    lVar12 = -lVar23;
                    if (-lVar23 < 0) {
                      lVar12 = lVar23;
                    }
                    if (lVar22 != 1) {
                      if (-1 < lVar23) {
LAB_23e309823:
                        plVar15 = (longlong *)
                                  FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar12,plVar14 + 3,lVar20);
                        goto LAB_23e3093ba;
                      }
                      goto LAB_23e30a0b2;
                    }
                    if (lVar23 < 0) {
LAB_23e30ad17:
                      plVar15 = (longlong *)FUN_23e8be680(plVar14,DAT_23ed6ccf8 + 0x18,lVar12);
                      lVar9 = -plVar15[2];
                      if (-1 < lVar9) {
                        lVar9 = plVar15[2];
                      }
                      plVar15[2] = lVar9;
                      goto LAB_23e3089ee;
                    }
                  }
                  plVar15 = (longlong *)
                            FUN_23e8beb80(plVar14,DAT_23ed6ccf8 + 0x18,lVar12,0xffffffff);
                }
                else if (lVar9 < 2) {
                  if (lVar23 < 0) {
                    lVar12 = -lVar23;
                    if (lVar23 != -1 && 0 < lVar12) {
                      if (lVar22 == 1) goto LAB_23e309ea4;
                      goto LAB_23e309d19;
                    }
                    iVar7 = 0;
                    if (lVar9 != 0) {
                      iVar7 = (int)plVar14[3];
                    }
LAB_23e30abdd:
                    iVar7 = iVar7 - *(int *)(DAT_23ed6ccf8 + 0x18);
                  }
                  else {
                    if (1 < lVar23) {
                      if (lVar22 == 1) goto LAB_23e3097eb;
                      goto LAB_23e3093a3;
                    }
                    iVar7 = 0;
                    if (lVar9 != 0) {
                      iVar7 = (int)plVar14[3];
                    }
LAB_23e30a842:
                    if (lVar23 != 0) {
                      iVar7 = iVar7 + *(int *)(DAT_23ed6ccf8 + 0x18);
                    }
                  }
                  if (lVar22 != 1) {
                    plVar15 = (longlong *)FUN_23e8bb5f0();
                    goto LAB_23e3093ba;
                  }
                  FUN_23e8be320(&local_78,iVar7);
                  plVar15 = local_78;
                }
                else {
                  lVar12 = -lVar23;
                  if (-lVar23 < 0) {
                    lVar12 = lVar23;
                  }
                  if (lVar22 == 1) {
                    bVar26 = lVar23 < 0;
                    lVar23 = lVar12;
                    if (bVar26) {
LAB_23e309ea4:
                      plVar15 = (longlong *)FUN_23e8beb80(plVar14,DAT_23ed6ccf8 + 0x18,lVar12,1);
                    }
                    else {
LAB_23e3097eb:
                      plVar15 = (longlong *)FUN_23e8be680(plVar14,DAT_23ed6ccf8 + 0x18,lVar23);
                    }
                  }
                  else {
                    bVar26 = lVar23 < 0;
                    lVar23 = lVar12;
                    if (bVar26) {
LAB_23e309d19:
                      plVar15 = (longlong *)
                                FUN_23e8be900(plVar14 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar12);
                    }
                    else {
LAB_23e3093a3:
                      plVar15 = (longlong *)
                                FUN_23e8be550(plVar14 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar23);
                      if (plVar15 == (longlong *)0x0) goto LAB_23e30a871;
                    }
LAB_23e3093ba:
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                  }
                }
LAB_23e3089ee:
                plVar14 = plVar15;
                iVar7 = FUN_23e97d380(plVar14,DAT_23eeaf600);
                plVar15 = DAT_23ed6ccf0;
                if (iVar7 == -1) {
                  uVar25 = 0xe3;
                  pcVar19 = *(code **)(param_1 + 0x60);
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  local_f0 = plVar18;
                  goto LAB_23e309066;
                }
                plVar16 = local_f0;
                if (iVar7 == 1) {
                  *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  local_78 = local_f0;
                  plVar14 = plVar15;
                  if ((code *)local_f0[1] == PyLong_Type_exref) {
                    lVar9 = local_f0[2];
                    lVar23 = *local_f0;
                    lVar22 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
                    if (lVar9 < 0) {
                      lVar12 = -lVar9;
                      if (lVar9 == -1 || lVar12 < 1) {
                        if (lVar22 < 0) {
                          lVar9 = -lVar22;
                          if (lVar22 == -1 || lVar9 < 1) {
                            iVar7 = -(int)local_f0[3];
                            goto LAB_23e30aee5;
                          }
                          if (lVar23 != 1) goto LAB_23e30aea5;
LAB_23e30acd8:
                          plVar16 = (longlong *)FUN_23e8be680(local_f0,DAT_23ed6ccf8 + 0x18,lVar9);
                          lVar9 = -plVar16[2];
                          if (-1 < lVar9) {
                            lVar9 = plVar16[2];
                          }
                          plVar16[2] = lVar9;
                          goto LAB_23e308a0f;
                        }
                        if (lVar22 < 2) {
                          iVar7 = -(int)local_f0[3];
                          goto LAB_23e30adde;
                        }
                        lVar9 = lVar22;
                        if (lVar23 != 1) goto LAB_23e30a771;
                      }
                      else {
                        lVar9 = -lVar22;
                        if (-lVar22 < 0) {
                          lVar9 = lVar22;
                        }
                        if (lVar23 != 1) {
                          bVar26 = lVar22 < 0;
                          lVar22 = lVar9;
                          if (bVar26) {
LAB_23e30aea5:
                            plVar16 = (longlong *)
                                      FUN_23e8be550(local_f0 + 3,lVar12,DAT_23ed6ccf8 + 0x18,lVar9);
                            plVar16[2] = -plVar16[2];
                          }
                          else {
LAB_23e30a771:
                            plVar16 = (longlong *)
                                      FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar22,local_f0 + 3,lVar12)
                            ;
                          }
                          goto LAB_23e309ab5;
                        }
                        if (lVar22 < 0) goto LAB_23e30acd8;
                      }
                      plVar16 = (longlong *)
                                FUN_23e8beb80(local_f0,DAT_23ed6ccf8 + 0x18,lVar9,0xffffffff);
                    }
                    else {
                      if (lVar9 < 2) {
                        if (lVar22 < 0) {
                          lVar12 = -lVar22;
                          if (lVar22 != -1 && 0 < lVar12) {
                            if (lVar23 == 1) goto LAB_23e30af62;
LAB_23e309ffa:
                            plVar16 = (longlong *)
                                      FUN_23e8be900(local_f0 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar12);
                            goto LAB_23e309ab5;
                          }
                          iVar7 = 0;
                          if (lVar9 != 0) {
                            iVar7 = (int)local_f0[3];
                          }
LAB_23e30aee5:
                          iVar7 = iVar7 - *(int *)(DAT_23ed6ccf8 + 0x18);
                        }
                        else {
                          if (1 < lVar22) {
                            if (lVar23 == 1) goto LAB_23e30aef6;
                            goto LAB_23e309a9e;
                          }
                          iVar7 = 0;
                          if (lVar9 != 0) {
                            iVar7 = (int)local_f0[3];
                          }
LAB_23e30adde:
                          if (lVar22 != 0) {
                            iVar7 = iVar7 + *(int *)(DAT_23ed6ccf8 + 0x18);
                          }
                        }
                        if (lVar23 == 1) {
                          FUN_23e8be320(&local_78,iVar7);
                          goto LAB_23e309489;
                        }
                        plVar16 = (longlong *)FUN_23e8bb5f0(iVar7);
                      }
                      else {
                        lVar12 = -lVar22;
                        if (-lVar22 < 0) {
                          lVar12 = lVar22;
                        }
                        if (lVar23 == 1) {
                          bVar26 = lVar22 < 0;
                          lVar22 = lVar12;
                          if (bVar26) {
LAB_23e30af62:
                            plVar16 = (longlong *)
                                      FUN_23e8beb80(local_f0,DAT_23ed6ccf8 + 0x18,lVar12,1);
                          }
                          else {
LAB_23e30aef6:
                            plVar16 = (longlong *)
                                      FUN_23e8be680(local_f0,DAT_23ed6ccf8 + 0x18,lVar22);
                          }
                          goto LAB_23e308a0f;
                        }
                        bVar26 = lVar22 < 0;
                        lVar22 = lVar12;
                        if (bVar26) goto LAB_23e309ffa;
LAB_23e309a9e:
                        plVar16 = (longlong *)
                                  FUN_23e8be550(local_f0 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar22);
                        if (plVar16 == (longlong *)0x0) goto LAB_23e30adff;
                      }
LAB_23e309ab5:
                      lVar9 = *local_f0;
                      *local_f0 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        (**(code **)(local_f0[1] + 0x30))(local_f0);
                      }
                    }
                  }
                  else {
                    cVar6 = FUN_23e8c7160(&local_78);
                    if (cVar6 == '\0') {
LAB_23e30adff:
                      uVar25 = 0xf1;
                      plVar15 = *(longlong **)(param_1 + 0x70);
                      pcVar19 = *(code **)(param_1 + 0x60);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar24 = *(undefined8 *)(param_1 + 0x68);
                      local_f0 = plVar18;
                      goto LAB_23e309066;
                    }
LAB_23e309489:
                    local_f0 = local_78;
                    plVar16 = local_f0;
                  }
                }
LAB_23e308a0f:
                local_f0 = plVar16;
                lVar9 = *(longlong *)(param_1 + 0x10);
                if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
                     (*(int *)(lVar9 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0))
                   && (pcVar19 = *(code **)(param_1 + 0x60), pcVar19 != (code *)0x0))
                goto LAB_23e309624;
                if (*(int *)(lVar9 + 0x68) == 0) {
                  plVar11 = *(longlong **)(param_1 + 0x90);
                }
                else {
                  PyEval_SaveThread();
                  PyEval_AcquireThread(param_1);
                  plVar11 = *(longlong **)(param_1 + 0x90);
                }
                local_a0 = plVar17;
                local_d8 = plVar18;
                local_a8 = local_f8;
                local_c8 = local_e0;
                local_c0 = local_e8;
              } while (plVar11 == (longlong *)0x0);
              plVar15 = *(longlong **)(param_1 + 0x60);
              plVar16 = *(longlong **)(param_1 + 0x68);
              plVar21 = *(longlong **)(param_1 + 0x70);
              *(longlong **)(param_1 + 0x60) = plVar11;
              *(undefined8 *)(param_1 + 0x90) = 0;
              *plVar11 = *plVar11 + 1;
              *(undefined8 *)(param_1 + 0x68) = 0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                (**(code **)(plVar21[1] + 0x30))(plVar21);
              }
              pcVar19 = *(code **)(param_1 + 0x60);
LAB_23e309624:
              plVar15 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar25 = 0xe5;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar11 = local_f0;
              uVar24 = *(undefined8 *)(param_1 + 0x68);
              local_f0 = plVar18;
LAB_23e309066:
              local_88[0] = (longlong *)0x0;
              local_98 = (undefined1  [16])0x0;
              lVar9 = *local_d0;
              *local_d0 = lVar9 + -1;
              local_a0 = plVar17;
              if (lVar9 + -1 == 0) {
                (**(code **)(local_d0[1] + 0x30))();
              }
            }
            lVar9 = *plVar13;
            *plVar13 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            local_98._8_8_ = uVar24;
            local_98._0_8_ = pcVar19;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e308c00;
          }
        }
        plVar15 = local_88[0];
        auVar5 = local_98;
        local_88[0] = (longlong *)0x0;
        local_98 = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        local_88[0] = (longlong *)0x0;
        local_98 = (undefined1  [16])0x0;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        uVar25 = 0xe2;
        plVar14 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        local_98 = auVar5;
        local_88[0] = plVar15;
        goto LAB_23e308bfd;
      }
      local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      plVar10 = (longlong *)0x0;
      if (*plVar8 == 0) goto LAB_23e30940c;
    }
LAB_23e309259:
    plVar8 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar25 = 0xbc;
  }
LAB_23e308bfd:
  local_e0 = (longlong *)0x0;
  local_e8 = (longlong *)0x0;
  local_f0 = (longlong *)0x0;
  local_f8 = (longlong *)0x0;
  local_a0 = (longlong *)0x0;
  plVar13 = DAT_23ed6a4f8;
  plVar15 = local_88[0];
joined_r0x00023e308c00:
  DAT_23ed6a4f8 = plVar13;
  local_88[0] = plVar15;
  if (plVar15 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar19 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar25;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar23 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar9;
    plVar13[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar13 + -2;
    plVar15 = plVar13;
    if ((local_88[0] != (longlong *)0x0) && (*local_88[0] = *local_88[0] + -1, *local_88[0] == 0)) {
      (**(code **)(local_88[0][1] + 0x30))(local_88[0]);
    }
  }
  else if ((longlong *)plVar15[3] != plVar3) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar19 = _PyRuntime_exref;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar25;
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar23 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar9;
    plVar13[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar13 + -2;
    plVar13[2] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    plVar15 = plVar13;
    if ((local_88[0] != (longlong *)0x0) && (*local_88[0] = *local_88[0] + -1, *local_88[0] == 0)) {
      (**(code **)(local_88[0][1] + 0x30))();
    }
  }
  local_88[0] = plVar15;
  FUN_23e8bba40(plVar3,"ooooooNooooo",plVar1,plVar2,plVar10,plVar8,plVar11,plVar14,0,local_a0,
                local_f8,local_f0,local_e8,local_e0);
  if (DAT_23eeb0708 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeb0708 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar9 + 0x28);
  plVar13 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar13 = local_88[0];
  auVar5 = local_98;
  plVar3[0xf] = 0;
  local_98 = (undefined1  [16])0x0;
  local_88[0] = (longlong *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((local_a0 != (longlong *)0x0) && (*local_a0 = *local_a0 + -1, *local_a0 == 0)) {
    (**(code **)(local_a0[1] + 0x30))(local_a0);
  }
  if ((local_f8 != (longlong *)0x0) && (lVar9 = *local_f8, *local_f8 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_f0 != (longlong *)0x0) && (lVar9 = *local_f0, *local_f0 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_f0[1] + 0x30))(local_f0);
  }
  if ((local_e8 != (longlong *)0x0) && (lVar9 = *local_e8, *local_e8 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  if ((local_e0 != (longlong *)0x0) && (lVar9 = *local_e0, *local_e0 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  local_98 = auVar5;
  local_88[0] = plVar13;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar9 = *plVar2;
  *plVar2 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88[0]);
  return (code *)0x0;
}
