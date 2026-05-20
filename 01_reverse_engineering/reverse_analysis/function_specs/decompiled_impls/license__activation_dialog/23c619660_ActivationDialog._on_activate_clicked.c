/* ===== 23c619660 license.activation_dialog:313 ===== */
/* ghidra_name=FUN_23c619660 entry=23c619660 size=8877 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23c619660(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  undefined1 auVar8 [16];
  char cVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined8 uVar15;
  longlong lVar16;
  code *pcVar17;
  longlong *plVar18;
  code *pcVar19;
  longlong *plVar20;
  code *pcVar21;
  longlong *plVar22;
  code *pcVar23;
  undefined4 uVar24;
  undefined1 auVar25 [8];
  code *pcVar26;
  code *local_e8;
  code *local_e0;
  code *local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  undefined1 local_78 [8];
  code *pcStack_70;
  code *local_68;
  
  plVar11 = DAT_23ee29eb8;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_68 = (code *)0x0;
  local_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (DAT_23ee29eb8 == (longlong *)0x0) {
LAB_23c6196c1:
    DAT_23ee29eb8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29eb0,DAT_23ee29f70,0x28);
  }
  else {
    lVar16 = *DAT_23ee29eb8;
    if (1 < lVar16) {
      *DAT_23ee29eb8 = lVar16 + -1;
      goto LAB_23c6196c1;
    }
    if (DAT_23ee29eb8[2] != 0) {
      *DAT_23ee29eb8 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23c6196c1;
    }
  }
  plVar3 = DAT_23ee29eb8;
  lVar16 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23ee29eb8 + 9;
  lVar14 = *(longlong *)(lVar16 + 8);
  DAT_23ee29eb8[0xf] = lVar14;
  *(longlong **)(lVar16 + 8) = plVar11;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar15 = DAT_23ee28f80;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uVar15);
  if (plVar11 == (longlong *)0x0) {
LAB_23c619890:
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcVar21 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x13c;
    plVar12 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23ee29468,plVar2);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23c619890;
    plVar11 = (longlong *)FUN_23a388310(plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23c619890;
    plVar12 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2);
      plVar13 = (longlong *)0x0;
      if (plVar12 != (longlong *)0x0) goto LAB_23c6197dd;
    }
    else {
LAB_23c6197dd:
      plVar13 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
      if (((plVar13 != (longlong *)0x0) ||
          (plVar13 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2), plVar13 != (longlong *)0x0))
         && (cVar9 = FUN_23a3884a0(param_1,local_78,plVar11,2), cVar9 != '\0')) {
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        iVar10 = FUN_23a35f020(plVar12);
        if (iVar10 == -1) {
          local_68 = *(code **)(param_1 + 0x70);
          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar24 = 0x13e;
          local_e8 = _PyRuntime_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c6198cf;
        }
        if (iVar10 == 0) {
          pcVar19 = (code *)FUN_23e8bc2f0(plVar1,DAT_23ee29428);
          plVar11 = DAT_23ee294a0;
          if (pcVar19 == (code *)0x0) {
            local_68 = *(code **)(param_1 + 0x70);
            local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_e8 = _PyRuntime_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            lVar16 = *(longlong *)(param_1 + 0x10);
            plVar20 = *(longlong **)(lVar16 + 0xe20);
            if (plVar20 == (longlong *)0x0) {
              plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar14 = plVar20[3];
              *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
              *(longlong *)(lVar16 + 0xe20) = lVar14;
              *plVar20 = 1;
            }
            local_e8 = _PyRuntime_exref;
            plVar20[4] = 0;
            lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8);
            lVar14 = plVar20[-1];
            puVar6 = *(undefined8 **)(lVar16 + 8);
            *puVar6 = plVar20 + -2;
            plVar20[-2] = lVar16;
            plVar20[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar6;
            *(longlong **)(lVar16 + 8) = plVar20 + -2;
            *plVar11 = *plVar11 + 1;
            plVar20[3] = (longlong)plVar11;
            uVar15 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar11 = plVar20;
              pcVar21 = pcVar19;
              plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar18 == (longlong *)0x0) goto LAB_23c61b5d0;
              *plVar18 = *plVar18 + 1;
              DAT_23ed6a4c0 = plVar18;
            }
            local_98._8_8_ = uVar15;
            local_98._0_8_ = plVar13;
            lVar16 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_98);
            if (lVar16 == 0) {
              local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              local_68 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
              if (*(longlong *)pcVar19 == 0) {
                (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
              }
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
            }
            else {
              plVar20[4] = lVar16;
              plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar20);
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
              uVar15 = DAT_23ee294a8;
              if (plVar11 == (longlong *)0x0) {
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                local_68 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                if (*(longlong *)pcVar19 == 0) {
                  (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
                }
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x143;
                local_98._8_8_ = uVar15;
                local_98._0_8_ = plVar11;
                plVar20 = (longlong *)FUN_23e94ed00(param_1,pcVar19,local_98);
                *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                if (*(longlong *)pcVar19 == 0) {
                  (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
                }
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar20 != (longlong *)0x0) {
                  *plVar20 = *plVar20 + -1;
                  if (*plVar20 == 0) {
                    (**(code **)(plVar20[1] + 0x30))(plVar20);
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee29268);
                  lVar16 = DAT_23ee29118;
                  if (plVar11 != (longlong *)0x0) {
                    *(undefined4 *)(plVar3 + 5) = 0x144;
                    plVar20 = (longlong *)
                              FUN_23e915840(param_1,plVar11,DAT_23ee29440,
                                            *(undefined8 *)(lVar16 + 0x18));
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (plVar20 != (longlong *)0x0) {
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        (**(code **)(plVar20[1] + 0x30))(plVar20);
                      }
                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
                      lVar16 = DAT_23ee29118;
                      if (plVar11 != (longlong *)0x0) {
                        *(undefined4 *)(plVar3 + 5) = 0x145;
                        plVar20 = (longlong *)
                                  FUN_23e915840(param_1,plVar11,DAT_23ee29440,
                                                *(undefined8 *)(lVar16 + 0x18));
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar20 != (longlong *)0x0) {
                          *plVar20 = *plVar20 + -1;
                          if (*plVar20 == 0) {
                            (**(code **)(plVar20[1] + 0x30))(plVar20);
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
                          if (plVar11 != (longlong *)0x0) {
                            *(undefined4 *)(plVar3 + 5) = 0x146;
                            plVar20 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23ee29390);
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              FUN_23a334bc0(plVar11);
                            }
                            if (plVar20 != (longlong *)0x0) {
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                FUN_23a334bc0(plVar20);
                              }
                              local_e0 = _Py_NoneStruct_exref;
                              goto LAB_23c61a498;
                            }
                          }
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68 = *(code **)(param_1 + 0x70);
                          uVar24 = 0x146;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23c6198cf;
                        }
                      }
                      local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_70 = *(code **)(param_1 + 0x68);
                      local_68 = *(code **)(param_1 + 0x70);
                      uVar24 = 0x145;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23c6198cf;
                    }
                  }
                  local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  local_68 = *(code **)(param_1 + 0x70);
                  uVar24 = 0x144;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c6198cf;
                }
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                local_68 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
            }
          }
          uVar24 = 0x143;
          goto LAB_23c6198cf;
        }
        pcVar21 = (code *)FUN_23e8bc2f0(plVar1,DAT_23ee29428);
        plVar20 = DAT_23ee29470;
        if (pcVar21 == (code *)0x0) {
          local_68 = *(code **)(param_1 + 0x70);
          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_e8 = _PyRuntime_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c61b636;
        }
        lVar16 = *(longlong *)(param_1 + 0x10);
        plVar11 = *(longlong **)(lVar16 + 0xe20);
        if (plVar11 == (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar14 = plVar11[3];
          *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
          *(longlong *)(lVar16 + 0xe20) = lVar14;
          *plVar11 = 1;
        }
        local_e8 = _PyRuntime_exref;
        plVar11[4] = 0;
        lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8);
        lVar14 = plVar11[-1];
        puVar6 = *(undefined8 **)(lVar16 + 8);
        *puVar6 = plVar11 + -2;
        plVar11[-2] = lVar16;
        plVar11[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar6;
        *(longlong **)(lVar16 + 8) = plVar11 + -2;
        *plVar20 = *plVar20 + 1;
        plVar11[3] = (longlong)plVar20;
        uVar15 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar20 == (longlong *)0x0) goto LAB_23c61b5d0;
          *plVar20 = *plVar20 + 1;
          DAT_23ed6a4c0 = plVar20;
        }
        local_98._8_8_ = uVar15;
        local_98._0_8_ = plVar13;
        lVar16 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_98);
        if (lVar16 == 0) goto LAB_23c61b5e3;
        plVar11[4] = lVar16;
        plVar20 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        uVar15 = DAT_23ee29478;
        if (plVar20 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          local_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
          if (*(longlong *)pcVar21 != 0) goto LAB_23c61b636;
          (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
          goto LAB_23c61b636;
        }
        *(undefined4 *)(plVar3 + 5) = 0x13f;
        local_98._8_8_ = uVar15;
        local_98._0_8_ = plVar20;
        plVar11 = (longlong *)FUN_23e94ed00(param_1,pcVar21,local_98);
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 == 0) {
          (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
        }
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
        }
        if (plVar11 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          local_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c61b636;
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee29480);
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0x140;
          plVar20 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23ee29488,plVar2);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar20 != (longlong *)0x0) {
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              (**(code **)(plVar20[1] + 0x30))(plVar20);
            }
            lVar16 = FUN_23ead6ad0();
            if (lVar16 == 0) {
              FUN_23e915740(param_1,local_78,DAT_23ee29350);
            }
            else {
              plVar11 = (longlong *)FUN_23e8bc2f0(lVar16,DAT_23ee29358);
              uVar15 = DAT_23ee29490;
              if (plVar11 != (longlong *)0x0) {
                plVar20 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee29498);
                if (plVar20 == (longlong *)0x0) {
                  local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  local_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  goto LAB_23c61b8f9;
                }
                *(undefined4 *)(plVar3 + 5) = 0x141;
                local_98._8_8_ = plVar20;
                local_98._0_8_ = uVar15;
                plVar18 = (longlong *)FUN_23e94ed00(param_1,plVar11,local_98);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                *plVar20 = *plVar20 + -1;
                if (*plVar20 == 0) {
                  FUN_23a334bc0(plVar20);
                }
                if (plVar18 != (longlong *)0x0) {
                  *plVar18 = *plVar18 + -1;
                  local_e0 = _Py_NoneStruct_exref;
                  if (*plVar18 == 0) {
                    FUN_23a334bc0(plVar18);
                  }
LAB_23c61a498:
                  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar11 = *(longlong **)(lVar16 + 0x28);
                  plVar3 = (longlong *)plVar11[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar16 + 0x30);
                  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                  if (plVar3 != (longlong *)0x0) {
                    plVar11[2] = 0;
                    *plVar3 = *plVar3 + -1;
                    if (*plVar3 == 0) {
                      (**(code **)(plVar3[1] + 0x30))();
                    }
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  plVar11[0xf] = 0;
                  *(longlong *)local_e0 = *(longlong *)local_e0 + 1;
                  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 == 0) {
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                    return local_e0;
                  }
                  return local_e0;
                }
              }
              local_68 = *(code **)(param_1 + 0x70);
              local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
LAB_23c61b8f9:
            uVar24 = 0x141;
            goto LAB_23c6198cf;
          }
        }
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68 = *(code **)(param_1 + 0x70);
        uVar24 = 0x140;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c6198cf;
      }
    }
    pcVar19 = local_68;
    pcVar21 = pcStack_70;
    auVar25 = local_78;
    local_68 = (code *)0x0;
    _local_78 = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    local_68 = (code *)0x0;
    local_78 = (undefined1  [8])0x0;
    pcStack_70 = (code *)0x0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
  }
  uVar24 = 0x13c;
  plVar13 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  local_e8 = _PyRuntime_exref;
  local_68 = pcVar19;
  local_78 = auVar25;
  pcStack_70 = pcVar21;
LAB_23c6198cf:
  do {
    pcVar19 = local_68;
    local_98._8_8_ = pcStack_70;
    local_98._0_8_ = local_78;
    local_68 = (code *)0x0;
    plVar20 = *(longlong **)(param_1 + 0x138);
    local_78 = (undefined1  [8])0x0;
    pcStack_70 = (code *)0x0;
    local_88[0] = pcVar19;
    if (plVar20 != (longlong *)0x0) {
      *plVar20 = *plVar20 + 1;
    }
    pcVar21 = DAT_23ed6a4f8;
    if (pcVar19 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar21 + 0x10) = 0;
      *(longlong **)(pcVar21 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar16 = *(longlong *)(local_e8 + 0x1f8);
      *(undefined4 *)(pcVar21 + 0x24) = uVar24;
      lVar16 = *(longlong *)(lVar16 + 0x10);
      *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
      lVar16 = *(longlong *)(lVar16 + 0x2e8);
      lVar14 = *(longlong *)(pcVar21 + -8);
      plVar11 = *(longlong **)(lVar16 + 8);
      *plVar11 = (longlong)(pcVar21 + -0x10);
      *(longlong *)(pcVar21 + -0x10) = lVar16;
      *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
      *(code **)(lVar16 + 8) = pcVar21 + -0x10;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar21 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar16 = *(longlong *)(local_e8 + 0x1f8);
      *(undefined4 *)(pcVar21 + 0x24) = uVar24;
      *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
      lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
      lVar14 = *(longlong *)(pcVar21 + -8);
      plVar11 = *(longlong **)(lVar16 + 8);
      *plVar11 = (longlong)(pcVar21 + -0x10);
      *(longlong *)(pcVar21 + -0x10) = lVar16;
      *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
      *(code **)(lVar16 + 8) = pcVar21 + -0x10;
      *(code **)(pcVar21 + 0x10) = pcVar19;
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
      }
    }
    pcVar19 = _Py_NoneStruct_exref;
    local_e0 = _Py_NoneStruct_exref;
    local_88[0] = pcVar21;
    if (((code *)local_98._0_8_ != _Py_NoneStruct_exref) && ((code *)local_98._0_8_ != (code *)0x0))
    {
      FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
    }
    plVar11 = *(longlong **)(local_98._8_8_ + 0x28);
    if (local_88[0] == pcVar19) {
      pcVar21 = (code *)0x0;
    }
    else {
      pcVar21 = local_88[0];
      if (local_88[0] != (code *)0x0) {
        *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
      }
    }
    *(code **)(local_98._8_8_ + 0x28) = pcVar21;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))();
    }
    plVar11 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))();
    }
    *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
    if (*(longlong *)local_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
    }
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
    pcVar21 = *(code **)(param_1 + 0x138);
    local_88[0] = (code *)0x0;
    local_98 = (undefined1  [16])0x0;
    pcVar17 = *(code **)PyExc_Exception_exref;
    pcVar23 = *(code **)(pcVar21 + 8);
    if ((*(uint *)(*(longlong *)(pcVar17 + 8) + 0xa8) & 0x4000000) == 0) {
      if ((-1 < (int)*(uint *)(*(longlong *)(pcVar17 + 8) + 0xa8)) ||
         (((byte)pcVar17[0xab] & 0x40) == 0)) {
        plVar18 = *(longlong **)PyExc_TypeError_exref;
        uVar15 = PyUnicode_FromString
                           ("catching classes that do not inherit from BaseException is not allowed"
                           );
        plVar22 = *(longlong **)(param_1 + 0x60);
        plVar5 = *(longlong **)(param_1 + 0x68);
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar18;
        *plVar18 = *plVar18 + 1;
        *(undefined8 *)(param_1 + 0x68) = uVar15;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
          (**(code **)(plVar22[1] + 0x30))();
        }
        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
LAB_23c619f92:
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        goto LAB_23c619fa1;
      }
      pcVar4 = *(code **)(pcVar23 + 8);
      pcVar26 = pcVar21;
      if ((*(uint *)(pcVar4 + 0xa8) & 0x40000000) == 0) {
        pcVar7 = pcVar23;
        if (((int)*(uint *)(pcVar4 + 0xa8) < 0) && (((byte)pcVar23[0xab] & 0x40) != 0)) {
LAB_23c619e94:
          lVar16 = *(longlong *)(pcVar23 + 0x158);
          if (lVar16 != 0) {
            if (*(longlong *)(lVar16 + 0x10) < 1) goto LAB_23c619b77;
            lVar14 = 0;
            while (pcVar17 != *(code **)(lVar16 + 0x18 + lVar14 * 8)) {
              lVar14 = lVar14 + 1;
              if (*(longlong *)(lVar16 + 0x10) == lVar14) goto LAB_23c619b77;
            }
            goto LAB_23c619fa8;
          }
          do {
            if (pcVar17 == pcVar23) goto LAB_23c619fa8;
            pcVar23 = *(code **)(pcVar23 + 0x100);
            pcVar7 = PyBaseObject_Type_exref;
          } while (pcVar23 != (code *)0x0);
        }
      }
      else {
        pcVar23 = pcVar4;
        pcVar7 = pcVar4;
        if (*(int *)(*(longlong *)(pcVar4 + 8) + 0xa8) < 0) goto LAB_23c619e94;
      }
      if (pcVar17 != pcVar7) goto LAB_23c619b77;
    }
    else {
      lVar16 = *(longlong *)(pcVar17 + 0x10);
      if (lVar16 < 1) {
LAB_23c619b77:
        pcStack_70 = pcVar21;
        if ((pcVar21 == pcVar19) || (pcVar21 == (code *)0x0)) {
          auVar25 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
          pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar19 = (code *)0x0;
          pcVar17 = *(code **)(param_1 + 0x138);
          local_e0._0_4_ = 0x13b;
          *(longlong *)auVar25 = *(longlong *)auVar25 + 1;
          goto LAB_23c61ab98;
        }
        auVar25 = *(undefined1 (*) [8])(pcVar21 + 8);
        pcVar19 = *(code **)(pcVar21 + 0x28);
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
        *(longlong *)auVar25 = *(longlong *)auVar25 + 1;
        pcVar17 = pcVar21;
        if (pcVar19 == (code *)0x0) {
          *(longlong **)(param_1 + 0x138) = plVar20;
          local_e0._0_4_ = 0;
        }
        else {
          *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
          if (*(longlong **)(pcVar19 + 0x18) == plVar3) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar19 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar20;
          local_e0._0_4_ = 0;
        }
        goto LAB_23c619bf0;
      }
      lVar14 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar17 + lVar14 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar17 + lVar14 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar18 = *(longlong **)PyExc_TypeError_exref;
          uVar15 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar22 = *(longlong **)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar5 = *(longlong **)(param_1 + 0x68);
          *(longlong **)(param_1 + 0x60) = plVar18;
          *plVar18 = *plVar18 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar15;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
            (**(code **)(plVar22[1] + 0x30))();
          }
          if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
            (**(code **)(plVar5[1] + 0x30))(plVar5);
          }
          goto LAB_23c619f92;
        }
        lVar14 = lVar14 + 1;
      } while (lVar16 != lVar14);
      lVar14 = 0;
      while (iVar10 = FUN_23a444d40(param_1,pcVar23), iVar10 == 0) {
        lVar14 = lVar14 + 1;
        if (lVar16 == lVar14) {
          pcVar21 = *(code **)(param_1 + 0x138);
          goto LAB_23c619b77;
        }
      }
LAB_23c619fa1:
      pcVar26 = *(code **)(param_1 + 0x138);
    }
LAB_23c619fa8:
    *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
    lVar16 = FUN_23ead6980();
    if (lVar16 == 0) {
      FUN_23e915740(param_1,local_78,DAT_23ee294b0);
      local_e0._0_4_ = 0x148;
      pcVar21 = pcStack_70;
      pcVar19 = local_68;
      auVar25 = local_78;
      goto LAB_23c61ab40;
    }
    pcVar17 = (code *)FUN_23e8bc2f0(lVar16,DAT_23ee294a8);
    plVar11 = DAT_23ee294b8;
    if (pcVar17 == (code *)0x0) {
LAB_23c61ac80:
      auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
      local_e0._0_4_ = 0x148;
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar21 = *(code **)(param_1 + 0x68);
      goto LAB_23c61ab40;
    }
    lVar16 = *(longlong *)(param_1 + 0x10);
    plVar18 = *(longlong **)(lVar16 + 0xe20);
    if (plVar18 == (longlong *)0x0) {
      plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar14 = plVar18[3];
      *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
      *(longlong *)(lVar16 + 0xe20) = lVar14;
      *plVar18 = 1;
    }
    plVar18[4] = 0;
    lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8);
    lVar14 = plVar18[-1];
    puVar6 = *(undefined8 **)(lVar16 + 8);
    *puVar6 = plVar18 + -2;
    plVar18[-2] = lVar16;
    plVar18[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar16 + 8) = plVar18 + -2;
    *plVar11 = *plVar11 + 1;
    plVar18[3] = (longlong)plVar11;
    uVar15 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar11 = plVar18;
      pcVar21 = pcVar17;
      plVar22 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar22 != (longlong *)0x0) {
        *plVar22 = *plVar22 + 1;
        DAT_23ed6a4c0 = plVar22;
        goto LAB_23c61a084;
      }
    }
    else {
LAB_23c61a084:
      uStack_a0 = uVar15;
      local_a8 = pcVar26;
      lVar16 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
      if (lVar16 == 0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
        if (*(longlong *)pcVar17 == 0) {
          (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
        }
        *plVar18 = *plVar18 + -1;
        if (*plVar18 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
          local_e0._0_4_ = 0x148;
          pcVar21 = pcStack_70;
          pcVar19 = local_68;
          auVar25 = local_78;
        }
        else {
          local_e0._0_4_ = 0x148;
          pcVar21 = pcStack_70;
          pcVar19 = local_68;
          auVar25 = local_78;
        }
        goto LAB_23c61ab40;
      }
      plVar18[4] = lVar16;
      plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar18);
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      if (plVar11 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_e0._0_4_ = 0x148;
        local_68 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
        pcVar21 = pcStack_70;
        pcVar19 = local_68;
        auVar25 = local_78;
        if (*(longlong *)pcVar17 != 0) goto LAB_23c61ab40;
        local_e0._0_4_ = 0x148;
        lVar16 = *(longlong *)(pcVar17 + 8);
        goto LAB_23c61af78;
      }
      *(undefined4 *)(plVar3 + 5) = 0x148;
      plVar18 = (longlong *)FUN_23e914090(param_1,pcVar17);
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
      if (*(longlong *)pcVar17 == 0) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar18 == (longlong *)0x0) goto LAB_23c61ac80;
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      pcVar17 = (code *)FUN_23e8bc2f0(plVar1,DAT_23ee29428);
      plVar11 = DAT_23ee294c0;
      if (pcVar17 == (code *)0x0) goto LAB_23c61afa0;
      lVar16 = *(longlong *)(param_1 + 0x10);
      plVar18 = *(longlong **)(lVar16 + 0xe20);
      if (plVar18 == (longlong *)0x0) {
        plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar14 = plVar18[3];
        *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
        *(longlong *)(lVar16 + 0xe20) = lVar14;
        *plVar18 = 1;
      }
      plVar18[4] = 0;
      lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8);
      lVar14 = plVar18[-1];
      puVar6 = *(undefined8 **)(lVar16 + 8);
      *puVar6 = plVar18 + -2;
      plVar18[-2] = lVar16;
      plVar18[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar6;
      *(longlong **)(lVar16 + 8) = plVar18 + -2;
      *plVar11 = *plVar11 + 1;
      plVar18[3] = (longlong)plVar11;
      pcVar19 = (code *)FUN_23e8bd350(pcVar26);
      if (pcVar19 == (code *)0x0) goto LAB_23c61acf8;
      uVar15 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23c61a253;
      plVar11 = plVar18;
      pcVar21 = pcVar19;
      plVar22 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar22 != (longlong *)0x0) break;
    }
LAB_23c61b5d0:
    PyErr_PrintEx(0);
    Py_Exit(1);
LAB_23c61b5e3:
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
    if (*(longlong *)pcVar21 == 0) {
      (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
LAB_23c61b636:
    uVar24 = 0x13f;
  } while( true );
  *plVar22 = *plVar22 + 1;
  DAT_23ed6a4c0 = plVar22;
LAB_23c61a253:
  local_a8 = pcVar19;
  uStack_a0 = uVar15;
  lVar16 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
  *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
  if (*(longlong *)pcVar19 == 0) {
    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
  }
  if (lVar16 == 0) {
LAB_23c61acf8:
    local_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    _local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    lVar16 = *(longlong *)pcVar17;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar17 = lVar16 + -1;
    if (lVar16 + -1 == 0) {
      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
    }
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    local_e0._0_4_ = 0x149;
    pcVar21 = pcStack_70;
    pcVar19 = local_68;
    auVar25 = local_78;
  }
  else {
    plVar18[4] = lVar16;
    pcVar19 = (code *)PyUnicode_Join(DAT_23ed6cd28,plVar18);
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    uVar15 = DAT_23ee294a8;
    if (pcVar19 == (code *)0x0) {
      local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      local_e0._0_4_ = 0x149;
      pcStack_70 = *(code **)(param_1 + 0x68);
      local_68 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar16 = *(longlong *)pcVar17;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(longlong *)pcVar17 = lVar16 + -1;
      pcVar21 = pcStack_70;
      pcVar19 = local_68;
      auVar25 = local_78;
      if (lVar16 + -1 == 0) {
        local_e0._0_4_ = 0x149;
        lVar16 = *(longlong *)(pcVar17 + 8);
LAB_23c61af78:
        (**(code **)(lVar16 + 0x30))(pcVar17);
        pcVar21 = pcStack_70;
        pcVar19 = local_68;
        auVar25 = local_78;
      }
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x149;
      uStack_a0 = uVar15;
      local_a8 = pcVar19;
      plVar11 = (longlong *)FUN_23e94ed00(param_1,pcVar17,&local_a8);
      lVar16 = *(longlong *)pcVar17;
      *(longlong *)pcVar17 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
      }
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
      if (*(longlong *)pcVar19 == 0) {
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
      }
      if (plVar11 == (longlong *)0x0) {
LAB_23c61afa0:
        auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
        local_e0._0_4_ = 0x149;
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar21 = *(code **)(param_1 + 0x68);
      }
      else {
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee29268);
        lVar16 = DAT_23ee29118;
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0x14a;
          plVar18 = (longlong *)
                    FUN_23e915840(param_1,plVar11,DAT_23ee29440,*(undefined8 *)(lVar16 + 0x18));
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar18 != (longlong *)0x0) {
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
            lVar16 = DAT_23ee29118;
            if (plVar11 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0x14b;
              plVar18 = (longlong *)
                        FUN_23e915840(param_1,plVar11,DAT_23ee29440,*(undefined8 *)(lVar16 + 0x18));
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar18 != (longlong *)0x0) {
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
                if (*(longlong *)pcVar26 == 0) {
                  (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
                }
                plVar11 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar20;
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
                goto LAB_23c61a498;
              }
            }
            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
            local_e0._0_4_ = 0x14b;
            pcVar19 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar21 = *(code **)(param_1 + 0x68);
            goto LAB_23c61ab40;
          }
        }
        auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
        local_e0._0_4_ = 0x14a;
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar21 = *(code **)(param_1 + 0x68);
      }
    }
  }
LAB_23c61ab40:
  local_68 = (code *)0x0;
  _local_78 = (undefined1  [16])0x0;
  *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
  if (*(longlong *)pcVar26 == 0) {
    (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
  }
  pcVar17 = *(code **)(param_1 + 0x138);
LAB_23c61ab98:
  *(longlong **)(param_1 + 0x138) = plVar20;
  if (pcVar17 == (code *)0x0) {
    pcStack_70 = pcVar21;
    local_78 = auVar25;
    local_68 = pcVar19;
    if (pcVar19 != (code *)0x0) goto LAB_23c619c47;
LAB_23c61abe1:
    pcVar21 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar17 = local_68;
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar17 = (code *)0x0;
    }
    *(longlong *)(pcVar21 + 0x10) = 0;
    *(longlong **)(pcVar21 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar16 = *(longlong *)(local_e8 + 0x1f8);
    *(int *)(pcVar21 + 0x24) = (int)local_e0;
    lVar16 = *(longlong *)(lVar16 + 0x10);
    *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(lVar16 + 0x2e8);
    lVar14 = *(longlong *)(pcVar21 + -8);
    plVar11 = *(longlong **)(lVar16 + 8);
    *plVar11 = (longlong)(pcVar21 + -0x10);
    *(longlong *)(pcVar21 + -0x10) = lVar16;
    *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
    *(code **)(lVar16 + 8) = pcVar21 + -0x10;
  }
  else {
LAB_23c619bf0:
    local_68 = (code *)0x0;
    _local_78 = (undefined1  [16])0x0;
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
    if (*(longlong *)pcVar17 == 0) {
      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
    }
    pcStack_70 = pcVar21;
    local_78 = auVar25;
    if (pcVar19 == (code *)0x0) {
      local_68 = pcVar19;
      if ((int)local_e0 == 0) {
        local_e0._0_4_ = (int)plVar3[5];
      }
      goto LAB_23c61abe1;
    }
LAB_23c619c47:
    pcVar21 = DAT_23ed6a4f8;
    if (*(longlong **)(pcVar19 + 0x18) == plVar3) goto LAB_23c619d03;
    if ((int)local_e0 == 0) {
      local_e0._0_4_ = (int)plVar3[5];
    }
    local_68 = pcVar19;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar21 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar16 = *(longlong *)(local_e8 + 0x1f8);
    *(int *)(pcVar21 + 0x24) = (int)local_e0;
    *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar14 = *(longlong *)(pcVar21 + -8);
    plVar11 = *(longlong **)(lVar16 + 8);
    *plVar11 = (longlong)(pcVar21 + -0x10);
    *(longlong *)(pcVar21 + -0x10) = lVar16;
    *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
    *(code **)(lVar16 + 8) = pcVar21 + -0x10;
    *(code **)(pcVar21 + 0x10) = pcVar19;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    pcVar17 = local_68;
  }
  pcVar19 = pcVar21;
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
  }
LAB_23c619d03:
  local_68 = pcVar19;
  FUN_23e8bba40(plVar3,"ooooo",plVar1,plVar2,plVar12,plVar13,0);
  if (DAT_23ee29eb8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23ee29eb8 = (longlong *)0x0;
  }
  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar16 + 0x28);
  plVar3 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  pcVar19 = local_68;
  auVar8 = _local_78;
  plVar11[0xf] = 0;
  _local_78 = (undefined1  [16])0x0;
  local_68 = (code *)0x0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar1 = *plVar1 + -1;
  _local_78 = auVar8;
  local_68 = pcVar19;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78,pcStack_70,local_68);
  return (code *)0x0;
}
