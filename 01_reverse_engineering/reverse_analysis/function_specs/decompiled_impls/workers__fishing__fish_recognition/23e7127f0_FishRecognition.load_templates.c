/* ===== 23e7127f0 workers.fishing.fish_recognition:154 ===== */
/* ghidra_name=FUN_23e7127f0 entry=23e7127f0 size=7822 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7127f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  code *pcVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong *plVar12;
  code *pcVar13;
  code *pcVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong *plVar17;
  longlong lVar18;
  longlong *plVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  longlong *in_R10;
  code *pcVar22;
  bool bVar23;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong **local_a8;
  code *local_a0;
  longlong *local_98;
  undefined8 uStack_90;
  undefined1 local_88 [16];
  longlong *local_78 [7];
  
  plVar9 = _DAT_23eedb0a0;
  plVar2 = (longlong *)*param_3;
  local_78[0] = (longlong *)0x0;
  local_88 = (undefined1  [16])0x0;
  if (_DAT_23eedb0a0 == (longlong *)0x0) {
LAB_23e71285a:
    _DAT_23eedb0a0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb098,DAT_23eedb148,0x28);
  }
  else {
    lVar11 = *_DAT_23eedb0a0;
    if (1 < lVar11) {
      *_DAT_23eedb0a0 = lVar11 + -1;
      goto LAB_23e71285a;
    }
    if (_DAT_23eedb0a0[2] != 0) {
      *_DAT_23eedb0a0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e71285a;
    }
  }
  plVar19 = _DAT_23eedb0a0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedb0a0 + 9;
  lVar18 = *(longlong *)(lVar11 + 8);
  _DAT_23eedb0a0[0xf] = lVar18;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar19[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar19[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar19 = *plVar19 + 1;
  uVar10 = _DAT_23eed9ec0;
  *(undefined4 *)(plVar19 + 8) = 0;
  pcVar8 = (code *)FUN_23e8bc2f0(plVar2,uVar10);
  if (pcVar8 == (code *)0x0) {
    local_78[0] = *(longlong **)(param_1 + 0x70);
    local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    pcVar22 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x9c;
    local_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e713245;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed9f20);
  if (plVar9 == (longlong *)0x0) {
    local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_78[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
    plVar9 = (longlong *)0x0;
    if (*(longlong *)pcVar8 == 0) {
      pcVar22 = (code *)0x0;
      uVar20 = 0x9c;
      (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
      local_c8 = (longlong *)0x0;
      pcVar8 = (code *)0x0;
    }
    else {
      local_c8 = (longlong *)0x0;
      pcVar22 = (code *)0x0;
      pcVar8 = (code *)0x0;
      uVar20 = 0x9c;
    }
    goto LAB_23e713245;
  }
  local_c8 = (longlong *)FUN_23e8c6f80(pcVar8,plVar9);
  *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
  if (*(longlong *)pcVar8 == 0) {
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (local_c8 != (longlong *)0x0) {
    *(undefined4 *)(plVar19 + 5) = 0x9e;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,local_c8,DAT_23ed6cee0);
    if (plVar9 == (longlong *)0x0) {
      local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      pcVar22 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar20 = 0x9e;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      pcVar8 = (code *)0x0;
    }
    else {
      iVar7 = FUN_23a35f020(plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (iVar7 == -1) {
        local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_78[0] = *(longlong **)(param_1 + 0x70);
        uVar20 = 0x9e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar8 = (code *)0x0;
      }
      else if (iVar7 == 0) {
        uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
        plVar9 = _DAT_23eed9fb8;
        lVar11 = *(longlong *)(param_1 + 0x10);
        pcVar14 = *(code **)(lVar11 + 0xe20);
        if (pcVar14 == (code *)0x0) {
          pcVar14 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar18 = *(longlong *)(pcVar14 + 0x18);
          *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
          *(longlong *)(lVar11 + 0xe20) = lVar18;
          *(longlong *)pcVar14 = 1;
        }
        pcVar22 = _PyRuntime_exref;
        *(longlong *)(pcVar14 + 0x20) = 0;
        lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
        lVar18 = *(longlong *)(pcVar14 + -8);
        puVar3 = *(undefined8 **)(lVar11 + 8);
        *puVar3 = pcVar14 + -0x10;
        *(longlong *)(pcVar14 + -0x10) = lVar11;
        *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
        *(code **)(lVar11 + 8) = pcVar14 + -0x10;
        *plVar9 = *plVar9 + 1;
        *(longlong **)(pcVar14 + 0x18) = plVar9;
        uVar5 = DAT_23ed6cd28;
        plVar9 = (longlong *)&DAT_23ed6a4c0;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar12 == (longlong *)0x0) {
LAB_23e713f56:
            lVar11 = 0;
            PyErr_PrintEx(0);
            lVar18 = Py_Exit(1);
            pcVar13 = pcVar8;
LAB_23e713f69:
            plVar12 = (longlong *)-(longlong)plVar19;
            if (plVar19 == (longlong *)0xffffffffffffffff || (longlong)plVar12 < 1) {
              iVar7 = -(int)plVar9[3];
              goto LAB_23e7141d4;
            }
            lVar11 = lVar11 + 0x18;
            if (in_R10 != (longlong *)0x1) goto LAB_23e71410d;
LAB_23e713f87:
            plVar12 = (longlong *)FUN_23e8be680(plVar9,lVar11,plVar12);
            lVar11 = -plVar12[2];
            if (-1 < lVar11) {
              lVar11 = plVar12[2];
            }
            plVar12[2] = lVar11;
LAB_23e713170:
            do {
              plVar9 = plVar12;
              lVar11 = *(longlong *)(param_1 + 0x10);
              if ((((*(int *)(*(longlong *)(lVar11 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar11 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
                 (pcVar16 = *(code **)(param_1 + 0x60), pcVar16 != (code *)0x0)) goto LAB_23e7135f5;
              if (*(int *)(lVar11 + 0x68) == 0) {
                plVar12 = *(longlong **)(param_1 + 0x90);
              }
              else {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
                plVar12 = *(longlong **)(param_1 + 0x90);
              }
              pcVar8 = pcVar13;
              pcVar22 = pcVar14;
              if (plVar12 != (longlong *)0x0) goto LAB_23e713584;
LAB_23e712f10:
              lVar11 = local_b8[1];
              if (*(code **)(lVar11 + 0xe0) == (code *)0x0) goto LAB_23e713975;
              pcVar13 = (code *)(**(code **)(lVar11 + 0xe0))();
              plVar19 = local_c0;
              if (pcVar13 == (code *)0x0) goto LAB_23e713990;
              if (pcVar8 == (code *)0x0) {
                *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
              }
              else {
                *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
                if (*(longlong *)pcVar8 == 0) {
                  (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
                }
                *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
                *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
                if (*(longlong *)pcVar8 == 0) {
                  (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
                }
              }
              lVar11 = FUN_23e8e11f0();
              if (lVar11 == 0) goto LAB_23e713bfd;
              plVar12 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed9fd8);
              if (plVar12 == (longlong *)0x0) goto LAB_23e713e25;
              plVar17 = (longlong *)FUN_23e8bd350(pcVar13);
              if (plVar17 == (longlong *)0x0) goto LAB_23e713fb4;
              *(undefined4 *)(local_c0 + 5) = 0xa7;
              pcVar14 = (code *)FUN_23e914090(param_1,plVar12,plVar17);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              if (pcVar14 == (code *)0x0) goto LAB_23e713e25;
              if ((pcVar22 != (code *)0x0) &&
                 (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
                (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
              }
              plVar12 = plVar9;
            } while (pcVar14 == _Py_NoneStruct_exref);
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed9eb0);
            pcVar8 = pcVar14;
            if (plVar12 != (longlong *)0x0) {
              plVar17 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eed9d68);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              uVar10 = DAT_23ed6ce48;
              if (plVar17 != (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23e8bc2f0(pcVar13,_DAT_23eed9fe0);
                if (plVar12 == (longlong *)0x0) {
                  local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  local_78[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  uVar20 = 0xaa;
                  plVar12 = local_78[0];
                  pcVar16 = (code *)local_88._0_8_;
                  uVar10 = local_88._8_8_;
                  goto LAB_23e713630;
                }
                plVar15 = (longlong *)_PyDict_NewPresized(3);
                PyDict_SetItem(plVar15,uVar10,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                PyDict_SetItem(plVar15,_DAT_23eed9fe8,pcVar14);
                PyDict_SetItem(plVar15,DAT_23ed6ceb0,pcVar13);
                *(undefined4 *)(local_c0 + 5) = 0xa9;
                plVar12 = (longlong *)FUN_23e914090(param_1,plVar17,plVar15);
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (plVar12 != (longlong *)0x0) {
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar9 == (longlong *)0x0) {
                    local_88._8_8_ =
                         PyUnicode_FromFormat
                                   ("cannot access local variable \'%U\' where it is not associated with a value"
                                    ,_DAT_23eed9ff0);
                    local_88._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                    *(longlong *)local_88._0_8_ = *(longlong *)local_88._0_8_ + 1;
                    local_78[0] = (longlong *)0x0;
                    if ((code *)local_88._0_8_ != _Py_NoneStruct_exref) {
                      FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
                    }
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_88._8_8_);
                  }
                  else {
                    local_98 = plVar9;
                    if ((code *)plVar9[1] == PyLong_Type_exref) {
                      lVar4 = plVar9[2];
                      plVar19 = *(longlong **)(DAT_23ed6ccf8 + 0x10);
                      in_R10 = (longlong *)*plVar9;
                      lVar11 = DAT_23ed6ccf8;
                      if (-1 < lVar4) {
                        plVar12 = plVar19;
                        if (lVar4 < 2) {
                          if ((longlong)plVar19 < 0) {
                            plVar12 = (longlong *)-(longlong)plVar19;
                            if (plVar19 == (longlong *)0xffffffffffffffff || (longlong)plVar12 < 1)
                            {
                              iVar7 = 0;
                              if (lVar4 != 0) {
                                iVar7 = (int)plVar9[3];
                              }
LAB_23e7141d4:
                              iVar7 = iVar7 - *(int *)(lVar11 + 0x18);
                              goto LAB_23e71402f;
                            }
                            if (in_R10 == (longlong *)0x1) goto LAB_23e713f05;
LAB_23e7138e5:
                            plVar12 = (longlong *)
                                      FUN_23e8be900(plVar9 + 3,lVar4,DAT_23ed6ccf8 + 0x18,plVar12);
                            goto LAB_23e7136e0;
                          }
                          if ((longlong)plVar19 < 2) {
                            iVar7 = 0;
                            if (lVar4 != 0) {
                              iVar7 = (int)plVar9[3];
                            }
                            goto LAB_23e714027;
                          }
                          if (in_R10 != (longlong *)0x1) goto LAB_23e7136c9;
                        }
                        else {
                          plVar12 = (longlong *)-(longlong)plVar19;
                          if (-(longlong)plVar19 < 0) {
                            plVar12 = plVar19;
                          }
                          if (in_R10 != (longlong *)0x1) {
                            if (-1 < (longlong)plVar19) {
LAB_23e7136c9:
                              plVar12 = (longlong *)
                                        FUN_23e8be550(plVar9 + 3,lVar4,DAT_23ed6ccf8 + 0x18,plVar12)
                              ;
                              if (plVar12 != (longlong *)0x0) goto LAB_23e7136e0;
                              goto LAB_23e714053;
                            }
                            goto LAB_23e7138e5;
                          }
                          if ((longlong)plVar19 < 0) {
LAB_23e713f05:
                            plVar12 = (longlong *)
                                      FUN_23e8beb80(plVar9,DAT_23ed6ccf8 + 0x18,plVar12,1);
                            goto LAB_23e713170;
                          }
                        }
                        plVar12 = (longlong *)FUN_23e8be680(plVar9,DAT_23ed6ccf8 + 0x18,plVar12);
                        goto LAB_23e713170;
                      }
                      lVar18 = -lVar4;
                      if (lVar4 == -1 || lVar18 < 1) {
                        if ((longlong)plVar19 < 0) goto LAB_23e713f69;
                        if ((longlong)plVar19 < 2) {
                          iVar7 = -(int)plVar9[3];
LAB_23e714027:
                          if (plVar19 != (longlong *)0x0) {
                            iVar7 = iVar7 + *(int *)(DAT_23ed6ccf8 + 0x18);
                          }
LAB_23e71402f:
                          if (in_R10 == (longlong *)0x1) {
                            FUN_23e8be320(local_a8,iVar7);
                            plVar12 = local_98;
                            goto LAB_23e713170;
                          }
                          plVar12 = (longlong *)FUN_23e8bb5f0();
                        }
                        else {
                          plVar12 = plVar19;
                          if (in_R10 == (longlong *)0x1) goto LAB_23e713c81;
LAB_23e713e05:
                          in_R10 = plVar9 + 3;
                          plVar12 = (longlong *)
                                    FUN_23e8be900(DAT_23ed6ccf8 + 0x18,plVar19,in_R10,lVar18);
                        }
                      }
                      else {
                        plVar12 = (longlong *)-(longlong)plVar19;
                        if (-(longlong)plVar19 < 0) {
                          plVar12 = plVar19;
                        }
                        if (in_R10 == (longlong *)0x1) {
                          lVar11 = DAT_23ed6ccf8 + 0x18;
                          if (-1 < (longlong)plVar19) {
LAB_23e713c81:
                            plVar12 = (longlong *)
                                      FUN_23e8beb80(plVar9,DAT_23ed6ccf8 + 0x18,plVar12,0xffffffff);
                            goto LAB_23e713170;
                          }
                          goto LAB_23e713f87;
                        }
                        lVar11 = DAT_23ed6ccf8 + 0x18;
                        bVar23 = -1 < (longlong)plVar19;
                        plVar19 = plVar12;
                        if (bVar23) goto LAB_23e713e05;
LAB_23e71410d:
                        in_R10 = plVar9 + 3;
                        plVar12 = (longlong *)FUN_23e8be550(in_R10,lVar18,lVar11,plVar12);
                        plVar12[2] = -plVar12[2];
                      }
LAB_23e7136e0:
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      goto LAB_23e713170;
                    }
                    cVar6 = FUN_23e8c7160(local_a8);
                    plVar12 = local_98;
                    if (cVar6 != '\0') goto LAB_23e713170;
LAB_23e714053:
                    local_78[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  uVar20 = 0xae;
                  plVar19 = local_c0;
                  plVar12 = local_78[0];
                  pcVar16 = (code *)local_88._0_8_;
                  uVar10 = local_88._8_8_;
                  goto LAB_23e713630;
                }
              }
            }
            pcVar16 = *(code **)(param_1 + 0x60);
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar20 = 0xa9;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar10 = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e713630;
          }
          *plVar12 = *plVar12 + 1;
          DAT_23ed6a4c0 = plVar12;
        }
        uStack_90 = uVar5;
        local_98 = local_c8;
        lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_98);
        if (lVar11 == 0) {
          local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_78[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
          plVar9 = (longlong *)0x0;
          if (*(longlong *)pcVar14 == 0) {
            pcVar22 = (code *)0x0;
            uVar20 = 0x9f;
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
            pcVar8 = (code *)0x0;
          }
          else {
            pcVar22 = (code *)0x0;
            uVar20 = 0x9f;
            pcVar8 = (code *)0x0;
          }
        }
        else {
          *(longlong *)(pcVar14 + 0x20) = lVar11;
          plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar14);
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
          if (*(longlong *)pcVar14 == 0) {
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
          }
          if (plVar9 == (longlong *)0x0) {
            local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_78[0] = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar20 = 0x9f;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = (longlong *)0x0;
            pcVar8 = (code *)0x0;
          }
          else {
            *(undefined4 *)(plVar19 + 5) = 0x9f;
            plVar12 = (longlong *)FUN_23e914090(param_1,uVar10,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar12 != (longlong *)0x0) {
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              pcVar22 = (code *)0x0;
              pcVar13 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              lVar11 = *(longlong *)_Py_FalseStruct_exref;
              goto LAB_23e712b10;
            }
            local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_78[0] = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            plVar9 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar20 = 0x9f;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar8 = (code *)0x0;
          }
        }
      }
      else {
        pcVar14 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
        plVar9 = _DAT_23eed9fc0;
        lVar11 = *(longlong *)(param_1 + 0x10);
        plVar12 = *(longlong **)(lVar11 + 0xe20);
        if (plVar12 == (longlong *)0x0) {
          plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar18 = plVar12[3];
          *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
          *(longlong *)(lVar11 + 0xe20) = lVar18;
          *plVar12 = 1;
        }
        pcVar22 = _PyRuntime_exref;
        plVar12[4] = 0;
        lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
        lVar18 = plVar12[-1];
        puVar3 = *(undefined8 **)(lVar11 + 8);
        *puVar3 = plVar12 + -2;
        plVar12[-2] = lVar11;
        plVar12[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
        *(longlong **)(lVar11 + 8) = plVar12 + -2;
        plVar17 = DAT_23ed6a4c0;
        *plVar9 = *plVar9 + 1;
        plVar12[3] = (longlong)plVar9;
        uVar10 = DAT_23ed6cd28;
        if (plVar17 == (longlong *)0x0) {
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar17 == (longlong *)0x0) goto LAB_23e713f56;
          *plVar17 = *plVar17 + 1;
          DAT_23ed6a4c0 = plVar17;
        }
        local_a8 = &local_98;
        uStack_90 = uVar10;
        local_98 = local_c8;
        lVar11 = FUN_23e94ed00(param_1,plVar17,local_a8);
        if (lVar11 == 0) {
          local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_78[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar12 = *plVar12 + -1;
          plVar9 = (longlong *)0x0;
          if (*plVar12 == 0) {
            pcVar22 = (code *)0x0;
            uVar20 = 0xa2;
            (**(code **)(plVar12[1] + 0x30))(plVar12);
            pcVar8 = (code *)0x0;
          }
          else {
            pcVar22 = (code *)0x0;
            uVar20 = 0xa2;
            pcVar8 = (code *)0x0;
          }
        }
        else {
          plVar12[4] = lVar11;
          local_a0 = PyUnicode_Join_exref;
          plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar9 == (longlong *)0x0) {
            local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_78[0] = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar20 = 0xa2;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = (longlong *)0x0;
            pcVar8 = (code *)0x0;
          }
          else {
            *(undefined4 *)(plVar19 + 5) = 0xa2;
            plVar12 = (longlong *)FUN_23e914090(param_1,pcVar14,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar12 == (longlong *)0x0) {
              local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_78[0] = *(longlong **)(param_1 + 0x70);
              pcVar22 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar20 = 0xa2;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar8 = (code *)0x0;
            }
            else {
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              lVar11 = _DAT_23eed9fd0;
              uVar5 = _DAT_23eed9fc8;
              plVar9 = DAT_23ed6ccf0;
              *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
              uVar10 = *(undefined8 *)(lVar11 + 0x18);
              *(undefined4 *)(plVar19 + 5) = 0xa6;
              plVar12 = (longlong *)FUN_23e915840(param_1,local_c8,uVar5,uVar10);
              if (plVar12 == (longlong *)0x0) {
                local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_78[0] = *(longlong **)(param_1 + 0x70);
                pcVar22 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar20 = 0xa6;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar8 = (code *)0x0;
              }
              else {
                local_b8 = (longlong *)FUN_23ebf7180(plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                pcVar14 = _Py_NoneStruct_exref;
                if (local_b8 != (longlong *)0x0) {
                  local_c0 = plVar19;
                  if (plVar2 != (longlong *)0x0) {
                    pcVar8 = (code *)0x0;
                    pcVar22 = (code *)0x0;
                    goto LAB_23e712f10;
                  }
                  pcVar22 = (code *)0x0;
                  pcVar8 = (code *)0x0;
                  do {
                    while( true ) {
                      lVar11 = local_b8[1];
                      if (*(code **)(lVar11 + 0xe0) == (code *)0x0) goto LAB_23e713975;
                      pcVar13 = (code *)(**(code **)(lVar11 + 0xe0))(local_b8);
                      if (pcVar13 == (code *)0x0) goto LAB_23e713990;
                      if (pcVar8 == (code *)0x0) {
                        *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
                      }
                      else {
                        *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
                        if (*(longlong *)pcVar8 == 0) {
                          (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
                          lVar11 = *(longlong *)pcVar13;
                        }
                        else {
                          lVar11 = *(longlong *)pcVar13;
                        }
                        *(longlong *)pcVar13 = lVar11 + 1;
                        *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
                        if (*(longlong *)pcVar8 == 0) {
                          (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
                        }
                      }
                      lVar11 = FUN_23e8e11f0();
                      if (lVar11 == 0) goto LAB_23e713bfd;
                      plVar12 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed9fd8);
                      if (plVar12 == (longlong *)0x0) goto LAB_23e713e25;
                      plVar17 = (longlong *)FUN_23e8bd350(pcVar13);
                      if (plVar17 == (longlong *)0x0) goto LAB_23e713fb4;
                      *(undefined4 *)(plVar19 + 5) = 0xa7;
                      pcVar8 = (code *)FUN_23e914090(param_1,plVar12,plVar17);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      *plVar17 = *plVar17 + -1;
                      if (*plVar17 == 0) {
                        (**(code **)(plVar17[1] + 0x30))(plVar17);
                      }
                      if (pcVar8 == (code *)0x0) goto LAB_23e713e25;
                      if ((pcVar22 != (code *)0x0) &&
                         (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1,
                         *(longlong *)pcVar22 == 0)) {
                        (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
                      }
                      if (pcVar8 != pcVar14) {
                        local_88._8_8_ =
                             PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,DAT_23eed9d30);
                        local_88._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                        *(longlong *)local_88._0_8_ = *(longlong *)local_88._0_8_ + 1;
                        local_78[0] = (longlong *)0x0;
                        if ((code *)local_88._0_8_ != pcVar14) {
                          FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
                        }
                        uVar20 = 0xa9;
                        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_88._8_8_);
                        plVar12 = local_78[0];
                        pcVar16 = (code *)local_88._0_8_;
                        uVar10 = local_88._8_8_;
                        goto LAB_23e713630;
                      }
                      lVar11 = *(longlong *)(param_1 + 0x10);
                      uVar1 = *(uint *)(*(longlong *)(lVar11 + 0x28) + 0x160);
                      in_R10 = (longlong *)(ulonglong)uVar1;
                      if (((uVar1 != 0) || (*(int *)(lVar11 + 0x78) != 0)) &&
                         ((iVar7 = Py_MakePendingCalls(), iVar7 < 0 &&
                          (pcVar16 = *(code **)(param_1 + 0x60), pcVar16 != (code *)0x0))))
                      goto LAB_23e7135f5;
                      pcVar22 = pcVar14;
                      pcVar8 = pcVar13;
                      if (*(int *)(lVar11 + 0x68) == 0) break;
                      PyEval_SaveThread();
                      PyEval_AcquireThread(param_1);
                      plVar12 = *(longlong **)(param_1 + 0x90);
                      if (plVar12 != (longlong *)0x0) goto LAB_23e713584;
                    }
                    plVar12 = *(longlong **)(param_1 + 0x90);
                  } while (plVar12 == (longlong *)0x0);
LAB_23e713584:
                  plVar19 = *(longlong **)(param_1 + 0x60);
                  plVar17 = *(longlong **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x90) = 0;
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(longlong **)(param_1 + 0x60) = plVar12;
                  *plVar12 = *plVar12 + 1;
                  *(undefined8 *)(param_1 + 0x68) = 0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                    (**(code **)(plVar19[1] + 0x30))();
                  }
                  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  pcVar16 = *(code **)(param_1 + 0x60);
LAB_23e7135f5:
                  plVar12 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar20 = 0xa6;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar19 = local_c0;
                  pcVar8 = pcVar14;
                  uVar10 = *(undefined8 *)(param_1 + 0x68);
                  goto LAB_23e713630;
                }
                local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_78[0] = *(longlong **)(param_1 + 0x70);
                pcVar22 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar20 = 0xa6;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar8 = (code *)0x0;
              }
            }
          }
        }
      }
    }
    goto LAB_23e713245;
  }
  local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_78[0] = *(longlong **)(param_1 + 0x70);
  pcVar22 = (code *)0x0;
  pcVar8 = (code *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar9 = (longlong *)0x0;
  uVar21 = 0x9c;
  uVar20 = 0x9c;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (local_78[0] == (longlong *)0x0) goto LAB_23e712c60;
  goto LAB_23e71324e;
LAB_23e713975:
  PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
               *(undefined8 *)(lVar11 + 0x18));
  plVar19 = local_c0;
LAB_23e713990:
  pcVar13 = pcVar8;
  cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
  if (cVar6 == '\0') {
    plVar12 = *(longlong **)(param_1 + 0x70);
    pcVar16 = *(code **)(param_1 + 0x60);
    uVar10 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_78[0] = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_88 = (undefined1  [16])0x0;
    if (pcVar13 != (code *)0x0) {
      uVar20 = 0xa6;
      pcVar8 = pcVar22;
      goto LAB_23e713630;
    }
    pcVar13 = (code *)0x0;
    uVar20 = 0xa6;
    goto LAB_23e713641;
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
  local_c0 = (longlong *)*local_b8;
  *local_b8 = (longlong)local_c0 + -1;
  if ((longlong)local_c0 + -1 == 0) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
  plVar12 = _DAT_23eed9ff8;
  lVar11 = *(longlong *)(param_1 + 0x10);
  pcVar8 = *(code **)(lVar11 + 0xe28);
  if (pcVar8 == (code *)0x0) {
    local_c0 = _DAT_23eed9ff8;
    pcVar8 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar18 = *(longlong *)(pcVar8 + 0x18);
    *(int *)(lVar11 + 0xec0) = *(int *)(lVar11 + 0xec0) + -1;
    *(longlong *)(lVar11 + 0xe28) = lVar18;
    *(longlong *)pcVar8 = 1;
  }
  pcVar14 = _PyRuntime_exref;
  *(undefined1 (*) [16])(pcVar8 + 0x20) = (undefined1  [16])0x0;
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
  lVar18 = *(longlong *)(pcVar8 + -8);
  puVar3 = *(undefined8 **)(lVar11 + 8);
  *puVar3 = pcVar8 + -0x10;
  *(longlong *)(pcVar8 + -0x10) = lVar11;
  *(ulonglong *)(pcVar8 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
  *(code **)(lVar11 + 8) = pcVar8 + -0x10;
  *plVar12 = *plVar12 + 1;
  *(longlong **)(pcVar8 + 0x18) = plVar12;
  uVar5 = DAT_23ed6cd28;
  if (plVar9 == (longlong *)0x0) {
    FUN_23e8ba2b0(local_88,_DAT_23eed9ff0);
    if (((code *)local_88._0_8_ != _Py_NoneStruct_exref) && ((code *)local_88._0_8_ != (code *)0x0))
    {
      FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_88._8_8_);
    goto LAB_23e714529;
  }
  if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e713aa0;
  plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
  pcVar14 = pcVar13;
  if (plVar12 != (longlong *)0x0) goto code_r0x00023e71457c;
  goto LAB_23e713f56;
code_r0x00023e71457c:
  *plVar12 = *plVar12 + 1;
  DAT_23ed6a4c0 = plVar12;
LAB_23e713aa0:
  uStack_90 = uVar5;
  local_98 = plVar9;
  lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_a8);
  if (lVar11 == 0) {
    local_78[0] = *(longlong **)(param_1 + 0x70);
    local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e714529:
    *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
    if (*(longlong *)pcVar8 == 0) {
      FUN_23a334bc0(pcVar8);
    }
    uVar20 = 0xb0;
    pcVar8 = pcVar13;
    goto LAB_23e713245;
  }
  *(longlong *)(pcVar8 + 0x20) = lVar11;
  plVar12 = _DAT_23eeda000;
  *_DAT_23eeda000 = *_DAT_23eeda000 + 1;
  *(longlong **)(pcVar8 + 0x28) = plVar12;
  plVar12 = (longlong *)(*local_a0)(DAT_23ed6cd28,pcVar8);
  *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
  if (*(longlong *)pcVar8 == 0) {
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))();
  }
  if (plVar12 != (longlong *)0x0) {
    *(undefined4 *)(plVar19 + 5) = 0xb0;
    plVar17 = (longlong *)FUN_23e914090(param_1,uVar10);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if (plVar17 == (longlong *)0x0) goto LAB_23e7145df;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    iVar7 = FUN_23e97a530(plVar9);
    if (iVar7 == -1) {
      local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar20 = 0xb2;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar8 = pcVar13;
      goto LAB_23e713245;
    }
    if (iVar7 == 1) {
      uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar19 + 5) = 0xb3;
      plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar10,_DAT_23eeda008);
      if (plVar12 == (longlong *)0x0) {
        local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_78[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar20 = 0xb3;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar8 = pcVar13;
        goto LAB_23e713245;
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        FUN_23a334bc0(plVar12);
      }
      lVar11 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e712b10:
      pcVar8 = _Py_FalseStruct_exref;
      *(longlong *)_Py_FalseStruct_exref = lVar11 + 1;
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar19 = *(longlong **)(lVar11 + 0x28);
      plVar12 = (longlong *)plVar19[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
      *(undefined4 *)(plVar19 + 8) = 0xffffffff;
      if (plVar12 != (longlong *)0x0) {
        plVar19[2] = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
      }
      *plVar19 = *plVar19 + -1;
      if (*plVar19 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      plVar19[0xf] = 0;
      lVar11 = *local_c8;
      *local_c8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(local_c8[1] + 0x30))(local_c8);
      }
      if (plVar9 == (longlong *)0x0) goto LAB_23e712b93;
    }
    else {
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar19 = *(longlong **)(lVar11 + 0x28);
      plVar12 = (longlong *)plVar19[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
      *(undefined4 *)(plVar19 + 8) = 0xffffffff;
      if (plVar12 != (longlong *)0x0) {
        plVar19[2] = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
      }
      *plVar19 = *plVar19 + -1;
      if (*plVar19 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      plVar19[0xf] = 0;
      pcVar8 = _Py_TrueStruct_exref;
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
      lVar11 = *local_c8;
      *local_c8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(local_c8[1] + 0x30))();
      }
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
LAB_23e712b93:
    if ((pcVar13 != (code *)0x0) &&
       (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
    }
    if ((pcVar22 != (code *)0x0) &&
       (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
      (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
    }
    lVar11 = *plVar2;
    *plVar2 = lVar11 + -1;
    if (lVar11 + -1 != 0) {
      return pcVar8;
    }
    (**(code **)(plVar2[1] + 0x30))(plVar2);
    return pcVar8;
  }
LAB_23e7145df:
  local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_78[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar20 = 0xb0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  pcVar8 = pcVar13;
  goto LAB_23e713245;
LAB_23e713bfd:
  uVar20 = 0xa7;
  FUN_23e915740(param_1,local_88,_DAT_23eed9e40);
  plVar19 = local_c0;
  plVar12 = local_78[0];
  pcVar8 = pcVar22;
  pcVar16 = (code *)local_88._0_8_;
  uVar10 = local_88._8_8_;
  goto LAB_23e713630;
LAB_23e713e25:
  plVar12 = *(longlong **)(param_1 + 0x70);
  pcVar16 = *(code **)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar20 = 0xa7;
  plVar19 = local_c0;
  pcVar8 = pcVar22;
  uVar10 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e713630;
LAB_23e713fb4:
  local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
  local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
  local_78[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  uVar20 = 0xa7;
  plVar19 = local_c0;
  plVar12 = local_78[0];
  pcVar8 = pcVar22;
  pcVar16 = (code *)local_88._0_8_;
  uVar10 = local_88._8_8_;
LAB_23e713630:
  local_78[0] = (longlong *)0x0;
  local_88 = (undefined1  [16])0x0;
  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
  pcVar22 = pcVar8;
  if (*(longlong *)pcVar13 == 0) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
LAB_23e713641:
  lVar11 = *local_b8;
  *local_b8 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  local_88._8_8_ = uVar10;
  local_88._0_8_ = pcVar16;
  pcVar8 = pcVar13;
  local_78[0] = plVar12;
LAB_23e713245:
  uVar21 = uVar20;
  if (local_78[0] == (longlong *)0x0) {
LAB_23e712c60:
    plVar12 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar17 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar14 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar19;
    *plVar19 = *plVar19 + 1;
    lVar11 = *(longlong *)(pcVar14 + 0x1f8);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar20;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar18 = plVar12[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar12 + -2;
    plVar12[-2] = lVar11;
    plVar12[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar12 + -2;
    if ((local_78[0] != (longlong *)0x0) && (*local_78[0] = *local_78[0] + -1, *local_78[0] == 0)) {
      (**(code **)(local_78[0][1] + 0x30))(local_78[0]);
    }
  }
  else {
LAB_23e71324e:
    plVar12 = local_78[0];
    plVar17 = DAT_23ed6a4f8;
    if ((longlong *)local_78[0][3] != plVar19) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar14 = _PyRuntime_exref;
      plVar17[3] = (longlong)plVar19;
      *plVar19 = *plVar19 + 1;
      lVar11 = *(longlong *)(pcVar14 + 0x1f8);
      *(undefined4 *)(plVar17 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar17 + 0x24) = uVar21;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar18 = plVar17[-1];
      puVar3 = *(undefined8 **)(lVar11 + 8);
      *puVar3 = plVar17 + -2;
      plVar17[-2] = lVar11;
      plVar17[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
      *(longlong **)(lVar11 + 8) = plVar17 + -2;
      plVar17[2] = (longlong)plVar12;
      *plVar12 = *plVar12 + 1;
      plVar12 = plVar17;
      if ((local_78[0] != (longlong *)0x0) && (*local_78[0] = *local_78[0] + -1, *local_78[0] == 0))
      {
        (**(code **)(local_78[0][1] + 0x30))();
      }
    }
  }
  local_78[0] = plVar12;
  FUN_23e8bba40(plVar19,"ooooo",plVar2,local_c8,plVar9,pcVar8,pcVar22);
  if (_DAT_23eedb0a0 == plVar19) {
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    _DAT_23eedb0a0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar19 = *(longlong **)(lVar11 + 0x28);
  plVar12 = (longlong *)plVar19[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar19 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar19[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar19 = *plVar19 + -1;
  if (*plVar19 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  plVar12 = local_78[0];
  plVar19[0xf] = 0;
  uVar10 = local_88._0_8_;
  uVar5 = local_88._8_8_;
  local_88 = (undefined1  [16])0x0;
  local_78[0] = (longlong *)0x0;
  if ((local_c8 != (longlong *)0x0) &&
     (lVar11 = *local_c8, *local_c8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_c8[1] + 0x30))(local_c8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcVar8 != (code *)0x0) &&
     (*(longlong *)pcVar8 = *(longlong *)pcVar8 + -1, *(longlong *)pcVar8 == 0)) {
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
  }
  if ((pcVar22 != (code *)0x0) &&
     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
  lVar11 = *plVar2;
  *plVar2 = lVar11 + -1;
  local_78[0] = plVar12;
  local_88._0_8_ = uVar10;
  local_88._8_8_ = uVar5;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_88._0_8_,local_88._8_8_,local_78[0]);
  return (code *)0x0;
}
