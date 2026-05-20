/* ===== 23c618600 license.activation_dialog:298 ===== */
/* ghidra_name=FUN_23c618600 entry=23c618600 size=2639 */

code * FUN_23c618600(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined4 uVar12;
  code *pcVar13;
  undefined8 uVar14;
  longlong *plVar15;
  longlong *local_78;
  longlong *local_70;
  undefined8 local_68;
  longlong *plStack_60;
  longlong *local_58;
  
  plVar10 = DAT_23ed6a4e0;
  lVar8 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar10 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    plVar9 = DAT_23ed6a4e0;
  }
  else {
    plVar9 = (longlong *)*DAT_23ed6a4e0;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    plVar5 = plVar9;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar5;
  }
  pcVar13 = _PyRuntime_exref;
  plVar10[2] = lVar8;
  lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
  lVar1 = plVar10[-1];
  puVar2 = *(undefined8 **)(lVar8 + 8);
  *puVar2 = plVar10 + -2;
  plVar10[-2] = lVar8;
  plVar10[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar8 + 8) = plVar10 + -2;
  if (plVar9 == (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    DAT_23ed6a4e0 = (longlong *)*plVar9;
    *plVar9 = 1;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  plVar5 = DAT_23ee29ed8;
  lVar8 = *(longlong *)(pcVar13 + 0x1f8);
  plVar9[2] = 0;
  lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
  lVar1 = plVar9[-1];
  puVar2 = *(undefined8 **)(lVar8 + 8);
  *puVar2 = plVar9 + -2;
  plVar9[-2] = lVar8;
  plVar9[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar8 + 8) = plVar9 + -2;
  if (plVar5 == (longlong *)0x0) {
LAB_23c618716:
    plVar5 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29ed0,DAT_23ee29f70,0x10);
    DAT_23ee29ed8 = plVar5;
  }
  else {
    lVar8 = *plVar5;
    if (1 < lVar8) {
      *plVar5 = lVar8 + -1;
      goto LAB_23c618716;
    }
    if (plVar5[2] != 0) {
      *plVar5 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      goto LAB_23c618716;
    }
  }
  lVar8 = *(longlong *)(param_1 + 0x38);
  lVar1 = *(longlong *)(lVar8 + 8);
  plVar5[0xf] = lVar1;
  *(longlong **)(lVar8 + 8) = plVar5 + 9;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  lVar8 = plVar10[2];
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(lVar8,DAT_23ee291c8);
  if (plVar6 != (longlong *)0x0) {
    *(undefined4 *)(plVar5 + 5) = 300;
    plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,DAT_23ee29408);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    if (plVar7 != (longlong *)0x0) {
      plVar6 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ee29410);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar6 != (longlong *)0x0) {
        *(undefined4 *)(plVar5 + 5) = 300;
        plVar7 = (longlong *)FUN_23e9557e0(param_1,plVar6,DAT_23ee29418);
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        if (plVar7 != (longlong *)0x0) {
          plVar6 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ee29420);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar6 != (longlong *)0x0) {
            *(undefined4 *)(plVar5 + 5) = 300;
            lVar8 = FUN_23e91a870(param_1,plVar6);
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (lVar8 != 0) {
              plVar9[2] = lVar8;
              plVar6 = (longlong *)FUN_23e8bd600(param_1,lVar8);
              if (plVar6 == (longlong *)0x0) {
                uVar14 = *(undefined8 *)(param_1 + 0x60);
                plVar7 = *(longlong **)(param_1 + 0x68);
                uVar12 = 0x12e;
                plVar6 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
              }
              else {
                lVar8 = *plVar6 + -1;
                if ((plVar6[2] == 1) && ((int)plVar6[3] == 0x10)) {
                  *plVar6 = lVar8;
                  if (lVar8 == 0) {
                    (**(code **)(plVar6[1] + 0x30))();
                  }
                  lVar1 = DAT_23ee29438;
                  lVar8 = plVar10[2];
                  *(undefined4 *)(plVar5 + 5) = 0x132;
                  plVar6 = (longlong *)FUN_23e954670(param_1,lVar8,DAT_23ee29428,lVar1 + 0x18);
                  if (plVar6 == (longlong *)0x0) {
                    uVar14 = *(undefined8 *)(param_1 + 0x60);
                    plVar7 = *(longlong **)(param_1 + 0x68);
                    uVar12 = 0x132;
                    plVar6 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                  else {
                    *plVar6 = *plVar6 + -1;
                    if (*plVar6 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    plVar6 = (longlong *)FUN_23e8bc2f0(plVar10[2],DAT_23ee29268);
                    lVar8 = DAT_23ee293c0;
                    if (plVar6 != (longlong *)0x0) {
                      *(undefined4 *)(plVar5 + 5) = 0x133;
                      plVar7 = (longlong *)
                               FUN_23e915840(param_1,plVar6,DAT_23ee29440,
                                             *(undefined8 *)(lVar8 + 0x18));
                      *plVar6 = *plVar6 + -1;
                      if (*plVar6 == 0) {
                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                      }
                      if (plVar7 != (longlong *)0x0) {
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                        }
                        plVar6 = (longlong *)FUN_23e8bc2f0(plVar10[2],DAT_23ee291c8);
                        lVar8 = DAT_23ee293c0;
                        if (plVar6 != (longlong *)0x0) {
                          *(undefined4 *)(plVar5 + 5) = 0x134;
                          plVar7 = (longlong *)
                                   FUN_23e915840(param_1,plVar6,DAT_23ee29440,
                                                 *(undefined8 *)(lVar8 + 0x18));
                          *plVar6 = *plVar6 + -1;
                          if (*plVar6 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          if (plVar7 != (longlong *)0x0) {
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                            }
                            lVar8 = FUN_23ead6ad0();
                            uVar14 = DAT_23ee29360;
                            if (lVar8 == 0) {
                              FUN_23e915740(param_1,&local_68,DAT_23ee29350);
                              uVar14 = local_68;
                              plVar7 = plStack_60;
                            }
                            else {
                              *plVar9 = *plVar9 + 1;
                              uVar4 = DAT_23ee29ec8;
                              uVar3 = DAT_23ee29448;
                              *plVar10 = *plVar10 + 1;
                              local_78 = plVar9;
                              local_70 = plVar10;
                              plVar6 = (longlong *)
                                       FUN_23e93e1e0(FUN_23c6190c0,DAT_23ee29328,uVar3,uVar4,0,0,
                                                     DAT_23ee29f70,0,&local_78,2);
                              *(undefined4 *)(plVar5 + 5) = 0x137;
                              local_68 = uVar14;
                              plStack_60 = plVar6;
                              plVar7 = (longlong *)
                                       FUN_23e954670(param_1,lVar8,DAT_23ee29358,&local_68);
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                              if (plVar7 != (longlong *)0x0) {
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                plVar5 = *(longlong **)(lVar8 + 0x28);
                                plVar6 = (longlong *)plVar5[2];
                                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                     *(undefined8 *)(lVar8 + 0x30);
                                *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                                if (plVar6 != (longlong *)0x0) {
                                  plVar5[2] = 0;
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))();
                                  }
                                }
                                *plVar5 = *plVar5 + -1;
                                if (*plVar5 == 0) {
                                  (**(code **)(plVar5[1] + 0x30))(plVar5);
                                }
                                plVar5[0xf] = 0;
                                pcVar13 = _Py_NoneStruct_exref;
                                *(longlong *)_Py_NoneStruct_exref =
                                     *(longlong *)_Py_NoneStruct_exref + 1;
                                goto LAB_23c618967;
                              }
                              local_58 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar14 = *(undefined8 *)(param_1 + 0x60);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar7 = *(longlong **)(param_1 + 0x68);
                            }
                            uVar12 = 0x137;
                            plVar6 = local_58;
                            goto LAB_23c6189b1;
                          }
                        }
                        uVar14 = *(undefined8 *)(param_1 + 0x60);
                        plVar7 = *(longlong **)(param_1 + 0x68);
                        uVar12 = 0x134;
                        plVar6 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        goto LAB_23c6189b1;
                      }
                    }
                    uVar14 = *(undefined8 *)(param_1 + 0x60);
                    plVar7 = *(longlong **)(param_1 + 0x68);
                    uVar12 = 0x133;
                    plVar6 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                }
                else {
                  *plVar6 = lVar8;
                  if (lVar8 == 0) {
                    (**(code **)(plVar6[1] + 0x30))();
                  }
                  lVar1 = DAT_23ee29430;
                  lVar8 = plVar10[2];
                  *(undefined4 *)(plVar5 + 5) = 0x12f;
                  plVar6 = (longlong *)FUN_23e954670(param_1,lVar8,DAT_23ee29428,lVar1 + 0x18);
                  if (plVar6 != (longlong *)0x0) {
                    *plVar6 = *plVar6 + -1;
                    if (*plVar6 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    pcVar13 = _Py_NoneStruct_exref;
                    lVar8 = *(longlong *)(param_1 + 0x38);
                    lVar1 = *(longlong *)(lVar8 + 8);
                    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                    plVar5 = *(longlong **)(lVar1 + 0x28);
                    plVar6 = (longlong *)plVar5[2];
                    *(undefined8 *)(lVar8 + 8) = *(undefined8 *)(lVar1 + 0x30);
                    *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                    if (plVar6 != (longlong *)0x0) {
                      plVar5[2] = 0;
                      *plVar6 = *plVar6 + -1;
                      if (*plVar6 == 0) {
                        (**(code **)(plVar6[1] + 0x30))();
                      }
                    }
                    *plVar5 = *plVar5 + -1;
                    if (*plVar5 == 0) {
                      (**(code **)(plVar5[1] + 0x30))(plVar5);
                    }
                    plVar5[0xf] = 0;
LAB_23c618967:
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 != 0) {
                      return pcVar13;
                    }
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                    return pcVar13;
                  }
                  uVar14 = *(undefined8 *)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x68);
                  uVar12 = 0x12f;
                  plVar6 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
              }
              goto LAB_23c6189b1;
            }
          }
        }
      }
    }
  }
  plVar6 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar12 = 300;
  uVar14 = *(undefined8 *)(param_1 + 0x60);
  plVar7 = *(longlong **)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c6189b1:
  plVar11 = DAT_23ed6a4f8;
  if (plVar6 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar6 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar8 = *(longlong *)(pcVar13 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar1 = plVar11[-1];
    puVar2 = *(undefined8 **)(lVar8 + 8);
    *puVar2 = plVar11 + -2;
    plVar11[-2] = lVar8;
    plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar8 + 8) = plVar11 + -2;
    plVar15 = plVar11;
  }
  else {
    plVar15 = plVar6;
    if ((longlong *)plVar6[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar11[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar8 = *(longlong *)(pcVar13 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
      lVar8 = *(longlong *)(lVar8 + 0x10);
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar8 = *(longlong *)(lVar8 + 0x2e8);
      lVar1 = plVar11[-1];
      puVar2 = *(undefined8 **)(lVar8 + 8);
      *puVar2 = plVar11 + -2;
      plVar11[-2] = lVar8;
      plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
      lVar1 = *plVar6;
      *(longlong **)(lVar8 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar6;
      plVar15 = plVar11;
      if (lVar1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec479ed,plVar10,plVar9);
  if (DAT_23ee29ed8 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    DAT_23ee29ed8 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar8 + 0x28);
  plVar6 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  FUN_23a33aa70(param_1,uVar14,plVar7,plVar15);
  return (code *)0x0;
}
