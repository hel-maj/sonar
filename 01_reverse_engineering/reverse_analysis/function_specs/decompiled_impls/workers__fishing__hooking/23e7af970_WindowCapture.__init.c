/* ===== 23e7af970 workers.fishing.hooking:124 ===== */
/* ghidra_name=FUN_23e7af970 entry=23e7af970 size=2172 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7af970(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  code *pcVar10;
  char cVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong *plVar16;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar13 = _DAT_23eedab10;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  plVar4 = (longlong *)param_3[3];
  if (_DAT_23eedab10 == (longlong *)0x0) {
LAB_23e7af9b6:
    _DAT_23eedab10 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedab08,DAT_23eedab78,0x20);
  }
  else {
    lVar12 = *_DAT_23eedab10;
    if (1 < lVar12) {
      *_DAT_23eedab10 = lVar12 + -1;
      goto LAB_23e7af9b6;
    }
    if (_DAT_23eedab10[2] != 0) {
      *_DAT_23eedab10 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      goto LAB_23e7af9b6;
    }
  }
  plVar6 = _DAT_23eedab10;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar13 = _DAT_23eedab10 + 9;
  lVar5 = *(longlong *)(lVar12 + 8);
  _DAT_23eedab10[0xf] = lVar5;
  *(longlong **)(lVar12 + 8) = plVar13;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar13 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar13;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar9 = _DAT_23eed7ae0;
  *(undefined4 *)(plVar6 + 8) = 0;
  cVar11 = FUN_23e8d9ac0(plVar1,uVar9,plVar2);
  if (cVar11 == '\0') {
    uVar9 = *(undefined8 *)(param_1 + 0x60);
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x7d;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    plVar14 = DAT_23ed6a4f8;
  }
  else {
    cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7ae8,plVar3);
    if (cVar11 == '\0') {
      uVar9 = *(undefined8 *)(param_1 + 0x60);
      plVar13 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar8 = *(undefined8 *)(param_1 + 0x68);
      uVar15 = 0x7e;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar14 = DAT_23ed6a4f8;
    }
    else {
      cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7af0,plVar4);
      if (cVar11 == '\0') {
        uVar9 = *(undefined8 *)(param_1 + 0x60);
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x7f;
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = DAT_23ed6a4f8;
      }
      else {
        cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7af8,DAT_23ed6ccf0);
        uVar9 = DAT_23ed6cd08;
        if (cVar11 == '\0') {
          uVar9 = *(undefined8 *)(param_1 + 0x60);
          uVar8 = *(undefined8 *)(param_1 + 0x68);
          uVar15 = 0x80;
          plVar13 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar14 = DAT_23ed6a4f8;
        }
        else {
          lVar12 = FUN_23e8def00();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eed7b00);
            uVar15 = 0x81;
            uVar9 = uStack_68;
            plVar13 = plStack_58;
            uVar8 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
          }
          else {
            cVar11 = FUN_23e8d9ac0(lVar12,_DAT_23eed7b08,uVar9);
            if (cVar11 == '\0') {
              uVar9 = *(undefined8 *)(param_1 + 0x60);
              uVar15 = 0x81;
              plVar13 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar8 = *(undefined8 *)(param_1 + 0x68);
              plVar14 = DAT_23ed6a4f8;
            }
            else {
              lVar12 = FUN_23e8def00();
              if (lVar12 == 0) {
                FUN_23e915740(param_1,&uStack_68,_DAT_23eed7b00);
                uVar15 = 0x82;
                uVar9 = uStack_68;
                plVar13 = plStack_58;
                uVar8 = uStack_60;
                plVar14 = DAT_23ed6a4f8;
              }
              else {
                cVar11 = FUN_23e8d9ac0(lVar12,_DAT_23eed7b10,_Py_FalseStruct_exref);
                pcVar10 = _Py_NoneStruct_exref;
                if (cVar11 == '\0') {
                  uVar9 = *(undefined8 *)(param_1 + 0x60);
                  uVar15 = 0x82;
                  plVar13 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar8 = *(undefined8 *)(param_1 + 0x68);
                  plVar14 = DAT_23ed6a4f8;
                }
                else {
                  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b18,_Py_NoneStruct_exref);
                  if (cVar11 == '\0') {
                    uVar9 = *(undefined8 *)(param_1 + 0x60);
                    uVar15 = 0x85;
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar8 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = DAT_23ed6a4f8;
                  }
                  else {
                    cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b20,pcVar10);
                    if (cVar11 == '\0') {
                      uVar9 = *(undefined8 *)(param_1 + 0x60);
                      uVar15 = 0x86;
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar8 = *(undefined8 *)(param_1 + 0x68);
                      plVar14 = DAT_23ed6a4f8;
                    }
                    else {
                      *(undefined4 *)(plVar6 + 5) = 0x87;
                      plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23eed7b28);
                      if (plVar13 == (longlong *)0x0) {
                        uVar9 = *(undefined8 *)(param_1 + 0x60);
                        uVar15 = 0x87;
                        plVar13 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar8 = *(undefined8 *)(param_1 + 0x68);
                        plVar14 = DAT_23ed6a4f8;
                      }
                      else {
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b30,DAT_23ed6ccf0);
                        if (cVar11 == '\0') {
                          uVar9 = *(undefined8 *)(param_1 + 0x60);
                          uVar15 = 0x8a;
                          plVar13 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar8 = *(undefined8 *)(param_1 + 0x68);
                          plVar14 = DAT_23ed6a4f8;
                        }
                        else {
                          lVar12 = FUN_23e8dedb0();
                          if (lVar12 == 0) {
                            FUN_23e915740(param_1,&uStack_68,_DAT_23eed7b38);
                            uVar15 = 0x8b;
                            uVar9 = uStack_68;
                            plVar13 = plStack_58;
                            uVar8 = uStack_60;
                            plVar14 = DAT_23ed6a4f8;
                          }
                          else {
                            *(undefined4 *)(plVar6 + 5) = 0x8b;
                            plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar12);
                            if (plVar13 != (longlong *)0x0) {
                              cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b40,plVar13);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              if (cVar11 != '\0') {
                                cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b48,DAT_23ed6ccf0);
                                if (cVar11 != '\0') {
                                  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                  plVar13 = *(longlong **)(lVar12 + 0x28);
                                  plVar6 = (longlong *)plVar13[2];
                                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                       *(undefined8 *)(lVar12 + 0x30);
                                  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                                  if (plVar6 != (longlong *)0x0) {
                                    plVar13[2] = 0;
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))();
                                    }
                                  }
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  *(longlong *)pcVar10 = *(longlong *)pcVar10 + 1;
                                  plVar13[0xf] = 0;
                                  *plVar1 = *plVar1 + -1;
                                  if (*plVar1 == 0) {
                                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                                  }
                                  *plVar2 = *plVar2 + -1;
                                  if (*plVar2 == 0) {
                                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                                  }
                                  *plVar3 = *plVar3 + -1;
                                  if (*plVar3 == 0) {
                                    (**(code **)(plVar3[1] + 0x30))(plVar3);
                                  }
                                  *plVar4 = *plVar4 + -1;
                                  if (*plVar4 != 0) {
                                    return pcVar10;
                                  }
                                  (**(code **)(plVar4[1] + 0x30))(plVar4);
                                  return pcVar10;
                                }
                                uVar9 = *(undefined8 *)(param_1 + 0x60);
                                uVar15 = 0x8c;
                                plVar13 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar8 = *(undefined8 *)(param_1 + 0x68);
                                plVar14 = DAT_23ed6a4f8;
                                goto joined_r0x00023e7afed1;
                              }
                            }
                            uVar9 = *(undefined8 *)(param_1 + 0x60);
                            uVar15 = 0x8b;
                            plVar13 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar8 = *(undefined8 *)(param_1 + 0x68);
                            plVar14 = DAT_23ed6a4f8;
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
joined_r0x00023e7afed1:
  DAT_23ed6a4f8 = plVar14;
  if (plVar13 == (longlong *)0x0) {
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar14;
      *plVar14 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar10 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar12 = *(longlong *)(pcVar10 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar5 = plVar14[-1];
    puVar7 = *(undefined8 **)(lVar12 + 8);
    *puVar7 = plVar14 + -2;
    plVar14[-2] = lVar12;
    plVar14[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar12 + 8) = plVar14 + -2;
    plVar16 = plVar14;
  }
  else {
    plVar16 = plVar13;
    if ((longlong *)plVar13[3] != plVar6) {
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar14;
        *plVar14 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar14[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
      pcVar10 = _PyRuntime_exref;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar10 + 0x1f8) + 0x10) + 0x2e8);
      lVar5 = plVar14[-1];
      puVar7 = *(undefined8 **)(lVar12 + 8);
      *puVar7 = plVar14 + -2;
      plVar14[-2] = lVar12;
      plVar14[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar7;
      lVar5 = *plVar13;
      *(longlong **)(lVar12 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar13;
      plVar16 = plVar14;
      if (lVar5 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
  }
  FUN_23e8bba40(plVar6,&DAT_23ec5dee6,plVar1,plVar2,plVar3,plVar4);
  if (_DAT_23eedab10 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eedab10 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar12 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  plVar6 = (longlong *)plVar13[2];
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar13[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,uVar9,uVar8,plVar16);
  return (code *)0x0;
}
