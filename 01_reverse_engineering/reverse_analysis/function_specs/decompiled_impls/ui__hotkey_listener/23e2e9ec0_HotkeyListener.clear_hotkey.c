/* ===== 23e2e9ec0 ui.hotkey_listener:83 ===== */
/* ghidra_name=FUN_23e2e9ec0 entry=23e2e9ec0 size=3086 */

code * FUN_23e2e9ec0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  code *pcVar14;
  undefined4 uVar15;
  longlong *local_68;
  code *local_60;
  longlong *local_58;
  
  plVar8 = DAT_23eeb0128;
  plVar1 = (longlong *)*param_3;
  if (DAT_23eeb0128 == (longlong *)0x0) {
LAB_23e2e9efa:
    DAT_23eeb0128 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0120,DAT_23eeb0170,8);
  }
  else {
    lVar10 = *DAT_23eeb0128;
    if (1 < lVar10) {
      *DAT_23eeb0128 = lVar10 + -1;
      goto LAB_23e2e9efa;
    }
    if (DAT_23eeb0128[2] != 0) {
      *DAT_23eeb0128 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e2e9efa;
    }
  }
  plVar3 = DAT_23eeb0128;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eeb0128 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  DAT_23eeb0128[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar12 = DAT_23eead0c0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar12);
  if (plVar8 == (longlong *)0x0) goto LAB_23e2ea470;
  iVar7 = FUN_23a35f020(plVar8);
  lVar10 = *plVar8 + -1;
  if (iVar7 == -1) {
LAB_23e2ea808:
    plVar9 = *(longlong **)(param_1 + 0x60);
    pcVar14 = *(code **)(param_1 + 0x68);
    uVar15 = 0x55;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar8 = lVar10;
joined_r0x00023e2ea831:
    plVar13 = DAT_23ed6a4f8;
    if (lVar10 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      plVar13 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e2ea625;
  }
  *plVar8 = lVar10;
  if (lVar10 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (iVar7 == 0) goto LAB_23e2e9fcb;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
  if (plVar8 == (longlong *)0x0) goto LAB_23e2ea470;
  iVar7 = FUN_23a35f020(plVar8);
  lVar10 = *plVar8 + -1;
  if (iVar7 == -1) goto LAB_23e2ea808;
  *plVar8 = lVar10;
  if (lVar10 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (iVar7 != 0) {
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
    if (plVar8 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x55;
      plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eead148);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar13 != (longlong *)0x0) {
        iVar7 = FUN_23a35f020(plVar13);
        lVar10 = *plVar13 + -1;
        if (iVar7 == -1) {
          plVar9 = *(longlong **)(param_1 + 0x60);
          pcVar14 = *(code **)(param_1 + 0x68);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar13 = lVar10;
          if (lVar10 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          uVar15 = 0x55;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2ea625;
        }
        *plVar13 = lVar10;
        if (lVar10 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        pcVar14 = _Py_NoneStruct_exref;
        if (iVar7 == 1) {
          lVar10 = *(longlong *)(param_1 + 0x38);
          lVar2 = *(longlong *)(lVar10 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar8 = *(longlong **)(lVar2 + 0x28);
          plVar3 = (longlong *)plVar8[2];
          *(undefined8 *)(lVar10 + 8) = *(undefined8 *)(lVar2 + 0x30);
          *(undefined4 *)(plVar8 + 8) = 0xffffffff;
          if (plVar3 != (longlong *)0x0) {
            plVar8[2] = 0;
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))();
            }
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar8[0xf] = 0;
          goto LAB_23e2ea2d0;
        }
        goto LAB_23e2e9fcb;
      }
    }
LAB_23e2ea470:
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x55;
    plVar9 = *(longlong **)(param_1 + 0x60);
    pcVar14 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e2ea625;
  }
LAB_23e2e9fcb:
  pcVar14 = _Py_FalseStruct_exref;
  cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eead0c0,_Py_FalseStruct_exref);
  if (cVar6 == '\0') {
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar9 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x59;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar14 = *(code **)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e2ea625;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
  if (plVar8 != (longlong *)0x0) {
    iVar7 = FUN_23a35f020(plVar8);
    lVar10 = *plVar8 + -1;
    if (iVar7 == -1) {
      plVar9 = *(longlong **)(param_1 + 0x60);
      pcVar14 = *(code **)(param_1 + 0x68);
      uVar15 = 0x5a;
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar8 = lVar10;
      goto joined_r0x00023e2ea831;
    }
    *plVar8 = lVar10;
    if (lVar10 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (iVar7 == 0) goto LAB_23e2ea040;
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
    if (plVar8 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x5a;
      plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eead148);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar13 != (longlong *)0x0) {
        iVar7 = FUN_23a35f020(plVar13);
        lVar10 = *plVar13 + -1;
        if (iVar7 == -1) {
          plVar9 = *(longlong **)(param_1 + 0x60);
          pcVar14 = *(code **)(param_1 + 0x68);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar13 = lVar10;
          if (lVar10 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          uVar15 = 0x5a;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2ea625;
        }
        *plVar13 = lVar10;
        if (lVar10 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (iVar7 == 1) {
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
          if (plVar8 != (longlong *)0x0) {
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eead150);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            lVar10 = DAT_23eead158;
            if (plVar9 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0x5b;
              plVar8 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar10 + 0x18,DAT_23eead160);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar8 != (longlong *)0x0) {
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                goto LAB_23e2ea040;
              }
            }
          }
          plVar9 = *(longlong **)(param_1 + 0x60);
          pcVar14 = *(code **)(param_1 + 0x68);
          uVar15 = 0x5b;
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = DAT_23ed6a4f8;
        }
        else {
LAB_23e2ea040:
          pcVar5 = _Py_TrueStruct_exref;
          cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eead0c0,_Py_TrueStruct_exref);
          if (cVar6 == '\0') {
            plVar9 = *(longlong **)(param_1 + 0x60);
            pcVar14 = *(code **)(param_1 + 0x68);
            uVar15 = 0x5d;
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = DAT_23ed6a4f8;
          }
          else {
            cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eead0e0,pcVar14);
            if (cVar6 == '\0') {
              plVar9 = *(longlong **)(param_1 + 0x60);
              pcVar14 = *(code **)(param_1 + 0x68);
              uVar15 = 0x5e;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar13 = DAT_23ed6a4f8;
            }
            else {
              plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0b8);
              if (plVar8 != (longlong *)0x0) {
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eead168);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (plVar9 != (longlong *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0x5f;
                  plVar8 = (longlong *)FUN_23e91a870(param_1,plVar9);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar8 != (longlong *)0x0) {
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    lVar10 = FUN_23e8f5ec0();
                    if (lVar10 == 0) {
                      uVar15 = 0x61;
                      FUN_23e915740(param_1,&local_68,DAT_23eead0c8);
                      plVar11 = local_58;
                      plVar9 = local_68;
                      pcVar14 = local_60;
                      plVar13 = DAT_23ed6a4f8;
                    }
                    else {
                      plVar8 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead170);
                      if (plVar8 != (longlong *)0x0) {
                        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead178);
                        plVar9 = DAT_23eead180;
                        if (plVar11 == (longlong *)0x0) {
                          plVar9 = *(longlong **)(param_1 + 0x60);
                          pcVar14 = *(code **)(param_1 + 0x68);
                          plVar11 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          uVar15 = 0x62;
                          plVar13 = DAT_23ed6a4f8;
                          goto joined_r0x00023e2ea625;
                        }
                        *(undefined4 *)(plVar3 + 5) = 0x61;
                        local_60 = pcVar5;
                        local_58 = plVar9;
                        local_68 = plVar11;
                        plVar9 = (longlong *)FUN_23e9186b0(param_1,plVar8,&local_68,DAT_23eead188);
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar9 != (longlong *)0x0) {
                          cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eead0a0,plVar9);
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          if (cVar6 != '\0') {
                            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
                            if (plVar8 != (longlong *)0x0) {
                              *(undefined4 *)(plVar3 + 5) = 100;
                              plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eead190);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              if (plVar9 != (longlong *)0x0) {
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                *(undefined4 *)(plVar3 + 5) = 0x65;
                                plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar12,DAT_23eead198);
                                if (plVar8 != (longlong *)0x0) {
                                  *plVar8 = *plVar8 + -1;
                                  if (*plVar8 == 0) {
                                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                                  }
                                  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                  plVar8 = *(longlong **)(lVar10 + 0x28);
                                  plVar3 = (longlong *)plVar8[2];
                                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                       *(undefined8 *)(lVar10 + 0x30);
                                  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                                  if (plVar3 != (longlong *)0x0) {
                                    plVar8[2] = 0;
                                    *plVar3 = *plVar3 + -1;
                                    if (*plVar3 == 0) {
                                      (**(code **)(plVar3[1] + 0x30))();
                                    }
                                  }
                                  *plVar8 = *plVar8 + -1;
                                  if (*plVar8 == 0) {
                                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                                  }
                                  plVar8[0xf] = 0;
                                  pcVar14 = _Py_NoneStruct_exref;
                                  *(longlong *)_Py_NoneStruct_exref =
                                       *(longlong *)_Py_NoneStruct_exref + 1;
LAB_23e2ea2d0:
                                  *plVar1 = *plVar1 + -1;
                                  if (*plVar1 != 0) {
                                    return pcVar14;
                                  }
                                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                                  return pcVar14;
                                }
                                plVar9 = *(longlong **)(param_1 + 0x60);
                                uVar15 = 0x65;
                                plVar11 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcVar14 = *(code **)(param_1 + 0x68);
                                plVar13 = DAT_23ed6a4f8;
                                goto joined_r0x00023e2ea625;
                              }
                            }
                            plVar9 = *(longlong **)(param_1 + 0x60);
                            uVar15 = 100;
                            plVar11 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pcVar14 = *(code **)(param_1 + 0x68);
                            plVar13 = DAT_23ed6a4f8;
                            goto joined_r0x00023e2ea625;
                          }
                        }
                      }
                      plVar9 = *(longlong **)(param_1 + 0x60);
                      uVar15 = 0x61;
                      plVar11 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar14 = *(code **)(param_1 + 0x68);
                      plVar13 = DAT_23ed6a4f8;
                    }
                    goto joined_r0x00023e2ea625;
                  }
                }
              }
              plVar9 = *(longlong **)(param_1 + 0x60);
              pcVar14 = *(code **)(param_1 + 0x68);
              uVar15 = 0x5f;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar13 = DAT_23ed6a4f8;
            }
          }
        }
        goto joined_r0x00023e2ea625;
      }
    }
  }
  plVar9 = *(longlong **)(param_1 + 0x60);
  pcVar14 = *(code **)(param_1 + 0x68);
  uVar15 = 0x5a;
  plVar11 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e2ea625:
  DAT_23ed6a4f8 = plVar13;
  if (plVar11 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar13[3] = (longlong)plVar3;
    plVar13[2] = 0;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar2 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar10;
    plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar10 + 8) = plVar13 + -2;
    plVar8 = plVar13;
  }
  else {
    plVar8 = plVar11;
    if ((longlong *)plVar11[3] != plVar3) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
      lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
      lVar2 = plVar13[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar13 + -2;
      plVar13[-2] = lVar10;
      plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar11;
      *(longlong **)(lVar10 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar11;
      plVar8 = plVar13;
      if (lVar2 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5b149,plVar1);
  if (DAT_23eeb0128 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeb0128 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar11 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar9,pcVar14,plVar8);
  return (code *)0x0;
}
