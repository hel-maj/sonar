/* ===== 23c6178c0 license.activation_dialog:281 ===== */
/* ghidra_name=FUN_23c6178c0 entry=23c6178c0 size=3320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c6178c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined8 uVar17;
  undefined4 uVar18;
  longlong *plStack_58;
  longlong *plStack_50;
  
  plVar14 = DAT_23ed6a4e0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar14 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar9 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar9;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar7 = _PyRuntime_exref;
  plVar9 = _DAT_23ee29f08;
  plVar14[2] = 0;
  lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
  lVar3 = plVar14[-1];
  puVar4 = *(undefined8 **)(lVar12 + 8);
  *puVar4 = plVar14 + -2;
  plVar14[-2] = lVar12;
  plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar12 + 8) = plVar14 + -2;
  if (plVar9 == (longlong *)0x0) {
LAB_23c617976:
    plVar9 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29f00,DAT_23ee29f70,0x28);
    _DAT_23ee29f08 = plVar9;
  }
  else {
    lVar12 = *plVar9;
    if (1 < lVar12) {
      *plVar9 = lVar12 + -1;
      goto LAB_23c617976;
    }
    if (plVar9[2] != 0) {
      *plVar9 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23c617976;
    }
  }
  lVar12 = *(longlong *)(param_1 + 0x38);
  lVar3 = *(longlong *)(lVar12 + 8);
  plVar9[0xf] = lVar3;
  *(longlong **)(lVar12 + 8) = plVar9 + 9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar9[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar9[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar9 = *plVar9 + 1;
  *(undefined4 *)(plVar9 + 8) = 0;
  uVar17 = DAT_23ed6cd28;
  plVar10 = (longlong *)FUN_23ebf7180(plVar2);
  plVar11 = DAT_23ed6a4e0;
  if (plVar10 != (longlong *)0x0) {
    if (DAT_23ed6a4e0 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4e0;
      *DAT_23ed6a4e0 = 1;
      DAT_23ed6a4e0 = plVar13;
      DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar11[2] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar11[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar11 + -2;
    uVar6 = DAT_23ee29f70;
    uVar5 = DAT_23ee293f8;
    plVar11[-2] = lVar12;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar11 + -2;
    plStack_58 = plVar11;
    plVar11 = (longlong *)
              FUN_23e91ecd0(FUN_23c657e50,uVar6,DAT_23ee293f0,uVar5,_DAT_23ee29ef0,&plStack_58,1,
                            0x478);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    lVar12 = PyUnicode_Join(uVar17,plVar11);
    *plVar11 = *plVar11 + -1;
    uVar17 = _DAT_23ee29398;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
      uVar17 = _DAT_23ee29398;
    }
    _DAT_23ee29398 = uVar17;
    if (lVar12 != 0) {
      plVar14[2] = lVar12;
      uVar5 = DAT_23ed6ccf0;
      plVar11 = (longlong *)FUN_23e8bd600(param_1,lVar12);
      plVar10 = (longlong *)FUN_23e97e310(param_1,uVar5,plVar11,_DAT_23ee293a0);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar10 == (longlong *)0x0) {
        uVar17 = *(undefined8 *)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0x11f;
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        plVar15 = DAT_23ed6a4f8;
      }
      else {
        plVar11 = (longlong *)FUN_23ebf7180(plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar10 = DAT_23ed6a4e0;
        plVar13 = (longlong *)0x0;
        if (plVar11 != (longlong *)0x0) {
          *plVar14 = *plVar14 + 1;
          plStack_58 = plVar14;
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
          }
          else {
            DAT_23ed6a4e0 = (longlong *)*plVar10;
            *plVar10 = 1;
            DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
          }
          pcVar7 = _PyRuntime_exref;
          plVar10[2] = (longlong)plVar11;
          *plVar11 = *plVar11 + 1;
          lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = plVar10[-1];
          puVar4 = *(undefined8 **)(lVar12 + 8);
          *puVar4 = plVar10 + -2;
          uVar5 = DAT_23ee293f8;
          plVar10[-2] = lVar12;
          plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
          *(longlong **)(lVar12 + 8) = plVar10 + -2;
          plStack_50 = plVar10;
          plVar10 = (longlong *)
                    FUN_23e91ecd0(FUN_23c6574a0,DAT_23ee29f70,DAT_23ee293f0,uVar5,_DAT_23ee29ef8,
                                  &plStack_58,2,0x478);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          plVar13 = (longlong *)PyUnicode_Join(uVar17,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar13 != (longlong *)0x0) {
            iVar8 = FUN_23e986640(plVar13,plVar2);
            if (iVar8 == -1) {
              uVar17 = *(undefined8 *)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              plVar10 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar18 = 0x122;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar15 = DAT_23ed6a4f8;
            }
            else {
              plVar10 = (longlong *)0x0;
              if (iVar8 != 1) {
LAB_23c617cb9:
                lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar9 = *(longlong **)(lVar12 + 0x28);
                plVar11 = (longlong *)plVar9[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
                *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                if (plVar11 != (longlong *)0x0) {
                  plVar9[2] = 0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))();
                  }
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                plVar9[0xf] = 0;
                pcVar7 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar1 = *plVar1 + -1;
                if (*plVar1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                *plVar2 = *plVar2 + -1;
                if (*plVar2 != 0) {
                  return pcVar7;
                }
                (**(code **)(plVar2[1] + 0x30))(plVar2);
                return pcVar7;
              }
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
              if (plVar11 != (longlong *)0x0) {
                *(undefined4 *)(plVar9 + 5) = 0x123;
                plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23ee293a8);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar10 != (longlong *)0x0) {
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
                  lVar12 = DAT_23ee29118;
                  if (plVar11 != (longlong *)0x0) {
                    *(undefined4 *)(plVar9 + 5) = 0x124;
                    plVar15 = (longlong *)
                              FUN_23e915840(param_1,plVar11,_DAT_23ee293b0,
                                            *(undefined8 *)(lVar12 + 0x18));
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (plVar15 != (longlong *)0x0) {
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
                      if (plVar11 != (longlong *)0x0) {
                        *(undefined4 *)(plVar9 + 5) = 0x125;
                        plVar15 = (longlong *)FUN_23e915840(param_1,plVar11,_DAT_23ee293b8,plVar13);
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar15 != (longlong *)0x0) {
                          *plVar15 = *plVar15 + -1;
                          if (*plVar15 == 0) {
                            (**(code **)(plVar15[1] + 0x30))(plVar15);
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
                          lVar12 = DAT_23ee293c0;
                          if (plVar11 != (longlong *)0x0) {
                            *(undefined4 *)(plVar9 + 5) = 0x126;
                            plVar15 = (longlong *)
                                      FUN_23e915840(param_1,plVar11,_DAT_23ee293b0,
                                                    *(undefined8 *)(lVar12 + 0x18));
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            if (plVar15 != (longlong *)0x0) {
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                (**(code **)(plVar15[1] + 0x30))(plVar15);
                              }
                              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee291c8);
                              if (plVar11 != (longlong *)0x0) {
                                plVar16 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee293c8);
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                                }
                                if (plVar16 != (longlong *)0x0) {
                                  uVar17 = FUN_23a4450c0(_DAT_23ee293d0);
                                  plVar11 = (longlong *)FUN_23e8bd600(param_1,plVar13);
                                  *(undefined4 *)(plVar9 + 5) = 0x128;
                                  plStack_58 = plVar10;
                                  plStack_50 = plVar11;
                                  plVar15 = (longlong *)FUN_23e94ed00(param_1,uVar17,&plStack_58);
                                  *plVar11 = *plVar11 + -1;
                                  if (*plVar11 == 0) {
                                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                                  }
                                  if (plVar15 == (longlong *)0x0) {
                                    uVar17 = *(undefined8 *)(param_1 + 0x60);
                                    plVar11 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar18 = 0x128;
                                    uVar5 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar16 = *plVar16 + -1;
                                    plVar15 = DAT_23ed6a4f8;
                                    if (*plVar16 == 0) {
                                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                                      uVar18 = 0x128;
                                      plVar15 = DAT_23ed6a4f8;
                                    }
                                    goto joined_r0x00023c617dc2;
                                  }
                                  *(undefined4 *)(plVar9 + 5) = 0x128;
                                  plVar11 = (longlong *)FUN_23e914090(param_1,plVar16);
                                  *plVar16 = *plVar16 + -1;
                                  if (*plVar16 == 0) {
                                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                                  }
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                                  }
                                  if (plVar11 != (longlong *)0x0) {
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                                    }
                                    goto LAB_23c617cb9;
                                  }
                                }
                              }
                              uVar17 = *(undefined8 *)(param_1 + 0x60);
                              plVar11 = *(longlong **)(param_1 + 0x70);
                              uVar18 = 0x128;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar5 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar15 = DAT_23ed6a4f8;
                              goto joined_r0x00023c617dc2;
                            }
                          }
                          uVar17 = *(undefined8 *)(param_1 + 0x60);
                          plVar11 = *(longlong **)(param_1 + 0x70);
                          uVar18 = 0x126;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar5 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar15 = DAT_23ed6a4f8;
                          goto joined_r0x00023c617dc2;
                        }
                      }
                      uVar17 = *(undefined8 *)(param_1 + 0x60);
                      plVar11 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0x125;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar5 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar15 = DAT_23ed6a4f8;
                      goto joined_r0x00023c617dc2;
                    }
                  }
                  uVar17 = *(undefined8 *)(param_1 + 0x60);
                  plVar11 = *(longlong **)(param_1 + 0x70);
                  uVar18 = 0x124;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar5 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar15 = DAT_23ed6a4f8;
                  goto joined_r0x00023c617dc2;
                }
              }
              uVar17 = *(undefined8 *)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              uVar18 = 0x123;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar15 = DAT_23ed6a4f8;
            }
            goto joined_r0x00023c617dc2;
          }
        }
        uVar17 = *(undefined8 *)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0x11f;
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar15 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023c617dc2;
    }
  }
  plVar13 = (longlong *)0x0;
  uVar17 = *(undefined8 *)(param_1 + 0x60);
  plVar11 = *(longlong **)(param_1 + 0x70);
  plVar10 = (longlong *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar18 = 0x11c;
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar15 = DAT_23ed6a4f8;
joined_r0x00023c617dc2:
  DAT_23ed6a4f8 = plVar15;
  if (plVar11 == (longlong *)0x0) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    lVar12 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar18;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar3 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
    plVar16 = plVar15;
  }
  else {
    plVar16 = plVar11;
    if ((longlong *)plVar11[3] != plVar9) {
      if (plVar15 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar15;
        *plVar15 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar15[3] = (longlong)plVar9;
      *plVar9 = *plVar9 + 1;
      lVar12 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar15 + 0x24) = uVar18;
      *(undefined4 *)(plVar15 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar3 = plVar15[-1];
      puVar4 = *(undefined8 **)(lVar12 + 8);
      *puVar4 = plVar15 + -2;
      plVar15[-2] = lVar12;
      plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      lVar3 = *plVar11;
      *(longlong **)(lVar12 + 8) = plVar15 + -2;
      plVar15[2] = (longlong)plVar11;
      plVar16 = plVar15;
      if (lVar3 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar9,"oocoo",plVar1,plVar2,plVar14,plVar13,plVar10);
  if (_DAT_23ee29f08 == plVar9) {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    _DAT_23ee29f08 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar12 + 0x28);
  plVar11 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar17,uVar5,plVar16);
  return (code *)0x0;
}
