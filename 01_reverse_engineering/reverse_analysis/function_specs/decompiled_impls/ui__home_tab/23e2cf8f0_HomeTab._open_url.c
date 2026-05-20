/* ===== 23e2cf8f0 ui.home_tab:406 ===== */
/* ghidra_name=FUN_23e2cf8f0 entry=23e2cf8f0 size=2515 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e2cf8f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  code *pcVar9;
  code *pcVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong *plVar14;
  code *in_R10;
  code *pcStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  code *pcStack_70;
  undefined8 uStack_68;
  
  plVar14 = _DAT_23eeb02b0;
  plVar1 = (longlong *)*param_3;
  pcVar10 = (code *)param_3[1];
  if (_DAT_23eeb02b0 == (longlong *)0x0) {
LAB_23e2cf939:
    _DAT_23eeb02b0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb02a8,DAT_23eeb0380,0x28);
  }
  else {
    lVar11 = *_DAT_23eeb02b0;
    if (1 < lVar11) {
      *_DAT_23eeb02b0 = lVar11 + -1;
      goto LAB_23e2cf939;
    }
    if (_DAT_23eeb02b0[2] != 0) {
      *_DAT_23eeb02b0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e2cf939;
    }
  }
  plVar4 = _DAT_23eeb02b0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar14 = _DAT_23eeb02b0 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23eeb02b0[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar14;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  pcStack_88 = _DAT_23eeadf30;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar14 = (longlong *)&DAT_23ed6a498;
  *plVar4 = *plVar4 + 1;
  uStack_80 = DAT_23eeae258;
  *(undefined4 *)(plVar4 + 5) = 0x198;
  uStack_68 = DAT_23ed6ccf0;
  pcStack_78 = _Py_NoneStruct_exref;
  pcStack_70 = _Py_NoneStruct_exref;
  if (DAT_23ed6a498 == (longlong *)0x0) {
    plVar7 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
      DAT_23ed6a498 = plVar7;
      goto LAB_23e2cfa0b;
    }
LAB_23e2d02d0:
    PyErr_PrintEx(0,0);
    Py_Exit(1);
LAB_23e2d02e8:
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    plVar7 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = 0x1a2;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar10 = in_R10;
    plVar8 = DAT_23ed6a4f8;
  }
  else {
LAB_23e2cfa0b:
    plVar14 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,&pcStack_88);
    if (plVar14 == (longlong *)0x0) {
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar6 = *(undefined8 *)(param_1 + 0x68);
      uVar13 = 0x198;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = DAT_23ed6a4f8;
      goto joined_r0x00023e2cfde9;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(pcVar10,_DAT_23eeadda0);
    if (plVar7 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x19b;
      plVar8 = (longlong *)FUN_23e9557e0(param_1,plVar7,_DAT_23eeadf38);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar8 != (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeadda0);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar7 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0x19b;
          plVar8 = (longlong *)FUN_23e9557e0(param_1,plVar7,_DAT_23eeadf40);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar8 != (longlong *)0x0) {
            plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeadda0);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            uVar5 = _DAT_23eeadf48;
            if (plVar7 != (longlong *)0x0) {
              *(undefined4 *)(plVar4 + 5) = 0x19b;
              pcVar9 = (code *)FUN_23e9557e0(param_1,plVar7,uVar5);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              if (pcVar9 != (code *)0x0) {
                *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                if (*(longlong *)pcVar10 == 0) {
                  (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
                }
                plVar7 = (longlong *)FUN_23e8bc2f0(pcVar9,_DAT_23eeadda0);
                if (plVar7 != (longlong *)0x0) {
                  *(undefined4 *)(plVar4 + 5) = 0x19e;
                  in_R10 = (code *)FUN_23e9557e0(param_1,plVar7,_DAT_23eeadf50);
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                  }
                  if (in_R10 != (code *)0x0) {
                    *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
                    if (*(longlong *)pcVar9 == 0) {
                      (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
                    }
                    uStack_80 = uRam000000023eeadf68;
                    pcStack_88 = _DAT_23eeadf60;
                    uVar5 = _DAT_23eeadf58;
                    *(undefined4 *)(plVar4 + 5) = 0x1a2;
                    pcStack_78 = in_R10;
                    pcVar10 = (code *)FUN_23e9578c0(param_1,plVar14,uVar5,&pcStack_88);
                    if (pcVar10 != (code *)0x0) {
                      *(longlong *)in_R10 = *(longlong *)in_R10 + -1;
                      if (*(longlong *)in_R10 == 0) {
                        (**(code **)(*(longlong *)(in_R10 + 8) + 0x30))(in_R10);
                      }
                      plVar7 = _DAT_23eeadf70;
                      lVar11 = *(longlong *)(param_1 + 0x10);
                      plVar12 = *(longlong **)(lVar11 + 0xe28);
                      if (plVar12 == (longlong *)0x0) {
                        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                      }
                      else {
                        lVar2 = plVar12[3];
                        *(int *)(lVar11 + 0xec0) = *(int *)(lVar11 + 0xec0) + -1;
                        *(longlong *)(lVar11 + 0xe28) = lVar2;
                        *plVar12 = 1;
                      }
                      pcVar9 = _PyRuntime_exref;
                      *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                      lVar11 = *(longlong *)
                                (*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
                      lVar2 = plVar12[-1];
                      puVar3 = *(undefined8 **)(lVar11 + 8);
                      *puVar3 = plVar12 + -2;
                      plVar12[-2] = lVar11;
                      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                      *(longlong **)(lVar11 + 8) = plVar12 + -2;
                      *plVar7 = *plVar7 + 1;
                      plVar12[3] = (longlong)plVar7;
                      uVar5 = DAT_23ed6cd28;
                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                        plVar7 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                        if (plVar7 == (longlong *)0x0) goto LAB_23e2d02d0;
                        *plVar7 = *plVar7 + 1;
                        DAT_23ed6a4c0 = plVar7;
                      }
                      uStack_80 = uVar5;
                      pcStack_88 = pcVar10;
                      lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
                      if (lVar11 == 0) {
                        uVar5 = *(undefined8 *)(param_1 + 0x60);
                        uVar6 = *(undefined8 *)(param_1 + 0x68);
                        uVar13 = 0x1a9;
                        plVar7 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *plVar12 = *plVar12 + -1;
                        plVar8 = DAT_23ed6a4f8;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                          uVar13 = 0x1a9;
                          plVar8 = DAT_23ed6a4f8;
                        }
                      }
                      else {
                        plVar12[4] = lVar11;
                        plVar7 = _DAT_23eeadf78;
                        *_DAT_23eeadf78 = *_DAT_23eeadf78 + 1;
                        plVar12[5] = (longlong)plVar7;
                        plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        if (plVar7 != (longlong *)0x0) {
                          lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar4 = *(longlong **)(lVar11 + 0x28);
                          plVar8 = (longlong *)plVar4[2];
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar11 + 0x30);
                          *(undefined4 *)(plVar4 + 8) = 0xffffffff;
                          if (plVar8 != (longlong *)0x0) {
                            plVar4[2] = 0;
                            *plVar8 = *plVar8 + -1;
                            if (*plVar8 == 0) {
                              (**(code **)(plVar8[1] + 0x30))();
                            }
                          }
                          *plVar4 = *plVar4 + -1;
                          if (*plVar4 == 0) {
                            (**(code **)(plVar4[1] + 0x30))(plVar4);
                          }
                          plVar4[0xf] = 0;
                          *plVar7 = *plVar7 + 1;
                          *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                          if (*(longlong *)pcVar10 == 0) {
                            (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          *plVar1 = *plVar1 + -1;
                          if (*plVar1 != 0) {
                            return plVar7;
                          }
                          (**(code **)(plVar1[1] + 0x30))(plVar1);
                          return plVar7;
                        }
                        uVar5 = *(undefined8 *)(param_1 + 0x60);
                        uVar6 = *(undefined8 *)(param_1 + 0x68);
                        uVar13 = 0x1a9;
                        plVar7 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plVar8 = DAT_23ed6a4f8;
                      }
                      goto joined_r0x00023e2cfde9;
                    }
                    goto LAB_23e2d02e8;
                  }
                }
                uVar5 = *(undefined8 *)(param_1 + 0x60);
                uVar6 = *(undefined8 *)(param_1 + 0x68);
                plVar7 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar13 = 0x19e;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar10 = pcVar9;
                plVar8 = DAT_23ed6a4f8;
                goto joined_r0x00023e2cfde9;
              }
            }
          }
        }
      }
    }
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    uVar13 = 0x19b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = DAT_23ed6a4f8;
  }
joined_r0x00023e2cfde9:
  DAT_23ed6a4f8 = plVar8;
  if (plVar7 == (longlong *)0x0) {
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar8;
      *plVar8 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = plVar8[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar8 + -2;
    plVar8[-2] = lVar11;
    plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar8 + -2;
    plVar12 = plVar8;
  }
  else {
    plVar12 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (plVar8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar8;
        *plVar8 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar11 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar2 = plVar8[-1];
      puVar3 = *(undefined8 **)(lVar11 + 8);
      *puVar3 = plVar8 + -2;
      plVar8[-2] = lVar11;
      plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar7;
      *(longlong **)(lVar11 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar7;
      plVar12 = plVar8;
      if (lVar2 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,"oooNo",plVar1,pcVar10,plVar14,0,0);
  if (_DAT_23eeb02b0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb02b0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar11 + 0x28);
  plVar7 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((pcVar10 != (code *)0x0) &&
     (*(longlong *)pcVar10 = *(longlong *)pcVar10 + -1, *(longlong *)pcVar10 == 0)) {
    (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar12);
  return (longlong *)0x0;
}
