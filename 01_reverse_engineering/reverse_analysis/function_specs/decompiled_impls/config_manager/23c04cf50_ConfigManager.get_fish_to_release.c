/* ===== 23c04cf50 config_manager:100 ===== */
/* ghidra_name=FUN_23c04cf50 entry=23c04cf50 size=7937 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c04cf50(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined1 (*pauVar1) [16];
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auVar8 [16];
  bool bVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  char cVar13;
  int iVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong lVar18;
  code *pcVar19;
  longlong *plVar20;
  longlong *plVar21;
  code *pcVar22;
  code *pcVar23;
  undefined8 *puVar24;
  code *pcVar25;
  undefined4 uVar26;
  longlong *in_R11;
  code *pcVar27;
  code *pcStack_128;
  code *pcStack_120;
  code *pcStack_118;
  longlong *plStack_110;
  code *pcStack_e8;
  undefined8 uStack_e0;
  undefined1 auStack_d8 [16];
  code *apcStack_c8 [2];
  undefined1 auStack_b8 [16];
  code *pcStack_a8;
  undefined8 uStack_98;
  undefined8 uStack_90;
  longlong *plStack_88;
  code *pcStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar2 = (longlong *)*param_3;
  pcVar15 = (code *)FUN_23e970f30(param_1,_DAT_23ee07668);
  plVar16 = _DAT_23ee0b600;
  if (_DAT_23ee0b600 == (longlong *)0x0) {
LAB_23c04cfa4:
    _DAT_23ee0b600 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee0b5f8,DAT_23ee0b670,0x30);
  }
  else {
    lVar18 = *_DAT_23ee0b600;
    if (1 < lVar18) {
      *_DAT_23ee0b600 = lVar18 + -1;
      goto LAB_23c04cfa4;
    }
    if (_DAT_23ee0b600[2] != 0) {
      *_DAT_23ee0b600 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      goto LAB_23c04cfa4;
    }
  }
  plVar4 = _DAT_23ee0b600;
  lVar18 = *(longlong *)(param_1 + 0x38);
  plVar16 = _DAT_23ee0b600 + 9;
  lVar3 = *(longlong *)(lVar18 + 8);
  _DAT_23ee0b600[0xf] = lVar3;
  *(longlong **)(lVar18 + 8) = plVar16;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar16 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar16;
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = *plVar16 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar5 = _DAT_23ee075a8;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,uVar5);
  if (plVar16 == (longlong *)0x0) {
    pcStack_120 = *(code **)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_128 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar16 = (longlong *)0x0;
    if (pcVar22 == (code *)0x0) {
      pcVar19 = (code *)0x0;
      plVar17 = (longlong *)0x0;
      iVar14 = 0x77;
      pcStack_118 = _PyRuntime_exref;
LAB_23c04dfd7:
      pcVar23 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar23 + 0x10) = 0;
      *(longlong **)(pcVar23 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar18 = *(longlong *)(pcStack_118 + 0x1f8);
      *(int *)(pcVar23 + 0x24) = iVar14;
      lVar18 = *(longlong *)(lVar18 + 0x10);
      *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
      lVar18 = *(longlong *)(lVar18 + 0x2e8);
      lVar3 = *(longlong *)(pcVar23 + -8);
      puVar24 = *(undefined8 **)(lVar18 + 8);
      *puVar24 = pcVar23 + -0x10;
      *(longlong *)(pcVar23 + -0x10) = lVar18;
      *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar24;
      *(code **)(lVar18 + 8) = pcVar23 + -0x10;
      goto LAB_23c04db00;
    }
    if (*(longlong **)(pcVar22 + 0x18) == plVar4) {
      pcVar19 = (code *)0x0;
      plVar17 = (longlong *)0x0;
      pcVar23 = pcVar22;
      goto LAB_23c04db00;
    }
    pcVar19 = (code *)0x0;
    plVar17 = (longlong *)0x0;
    iVar14 = 0x77;
    pcStack_118 = _PyRuntime_exref;
  }
  else {
    plVar17 = (longlong *)FUN_23e9367b0(param_1,plVar16);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if (plVar17 == (longlong *)0x0) {
      pcStack_120 = *(code **)(param_1 + 0x60);
      pcVar22 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_128 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar17 = (longlong *)0x0;
      if (pcVar22 == (code *)0x0) {
        pcVar19 = (code *)0x0;
        plVar16 = (longlong *)0x0;
        iVar14 = 0x77;
        pcStack_118 = _PyRuntime_exref;
        goto LAB_23c04dfd7;
      }
      if (*(longlong **)(pcVar22 + 0x18) == plVar4) {
        pcVar19 = (code *)0x0;
        plVar16 = (longlong *)0x0;
        pcVar23 = pcVar22;
        goto LAB_23c04db00;
      }
      pcVar19 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      iVar14 = 0x77;
LAB_23c04d1b8:
      pcStack_118 = _PyRuntime_exref;
    }
    else {
      iVar14 = FUN_23a35f020(plVar17);
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
      if (iVar14 != -1) {
        if (iVar14 == 0) {
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
          pcVar19 = (code *)0x0;
          plVar17 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          pcVar22 = pcVar15;
LAB_23c04d09b:
          lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar4 = *(longlong **)(lVar18 + 0x28);
          plVar20 = (longlong *)plVar4[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
          *(undefined4 *)(plVar4 + 8) = 0xffffffff;
          if (plVar20 != (longlong *)0x0) {
            plVar4[2] = 0;
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              (**(code **)(plVar20[1] + 0x30))();
            }
          }
          *plVar4 = *plVar4 + -1;
          if (*plVar4 == 0) {
            (**(code **)(plVar4[1] + 0x30))(plVar4);
          }
          plVar4[0xf] = 0;
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) {
            (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
          }
          if (plVar16 == (longlong *)0x0) goto LAB_23c04d109;
LAB_23c04d0ff:
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
LAB_23c04d109:
          if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if ((pcVar19 != (code *)0x0) &&
             (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
            (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar22;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar22;
        }
        plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23ee075a8);
        if (plVar16 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          apcStack_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_110 = *(longlong **)(param_1 + 0x138);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar19 = (code *)0x0;
          if (plStack_110 == (longlong *)0x0) {
            if (apcStack_c8[0] == (code *)0x0) goto LAB_23c04eac8;
            pcStack_120 = _Py_NoneStruct_exref;
            plVar16 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            goto LAB_23c04d55c;
          }
          *plStack_110 = *plStack_110 + 1;
joined_r0x00023c04d54a:
          if (apcStack_c8[0] == (code *)0x0) {
            pcVar19 = (code *)0x0;
            plVar16 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            uVar26 = 0x7b;
            pcStack_120 = _Py_NoneStruct_exref;
            goto LAB_23c04d976;
          }
        }
        else {
          pcStack_128 = (code *)FUN_23e91c870(param_1,plVar16,DAT_23ed6ce80,DAT_23ee075c0);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (pcStack_128 == (code *)0x0) {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            apcStack_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_110 = *(longlong **)(param_1 + 0x138);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023c04de70:
            if (plStack_110 != (longlong *)0x0) {
              *plStack_110 = *plStack_110 + 1;
              goto joined_r0x00023c04d54a;
            }
          }
          else {
            plVar17 = (longlong *)FUN_23e8d9880(pcStack_128,DAT_23ed6cd90);
            if (plVar17 != (longlong *)0x0) {
              *(undefined4 *)(plVar4 + 5) = 0x7b;
              plVar16 = (longlong *)FUN_23e91a870(param_1,plVar17);
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              if (plVar16 != (longlong *)0x0) {
                in_R11 = (longlong *)FUN_23e8d9880(pcStack_128,DAT_23ed6cd98);
                pcStack_120 = _Py_NoneStruct_exref;
                plStack_110 = plVar16;
                if (in_R11 == (longlong *)0x0) {
                  pcVar27 = *(code **)(param_1 + 0x70);
                  pcVar19 = (code *)0x0;
                  plVar17 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar22 = *(code **)(param_1 + 0x60);
                  pcStack_118._0_4_ = 0x7b;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar16 = (longlong *)0x0;
                  pcVar23 = *(code **)(param_1 + 0x68);
                  pcVar10 = pcStack_78;
                  pcVar11 = pcStack_70;
                  pcVar12 = pcStack_68;
                  goto LAB_23c04e1f5;
                }
                *plVar16 = *plVar16 + 1;
                lVar18 = FUN_23eb1ba00();
                if (lVar18 == 0) {
                  pcVar19 = (code *)0x0;
                  FUN_23e915740(param_1,&uStack_98,DAT_23ee075c8);
                  pcStack_118 = _PyRuntime_exref;
                  pcStack_120._0_4_ = 0x7c;
                  plVar17 = (longlong *)0x0;
                  plVar20 = plStack_88;
                }
                else {
                  *(undefined4 *)(plVar4 + 5) = 0x7c;
                  plVar17 = (longlong *)FUN_23e915840(param_1,lVar18,DAT_23ee075d0,plVar16);
                  pcStack_118 = _PyRuntime_exref;
                  if (plVar17 == (longlong *)0x0) {
                    plVar20 = *(longlong **)(param_1 + 0x70);
                    uStack_98 = *(undefined8 *)(param_1 + 0x60);
                    uStack_90 = *(undefined8 *)(param_1 + 0x68);
                    pcVar19 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcStack_120._0_4_ = 0x7c;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                  else {
                    lVar18 = *(longlong *)(param_1 + 0x10);
                    puVar24 = *(undefined8 **)(lVar18 + 0xe20);
                    if (puVar24 == (undefined8 *)0x0) {
                      puVar24 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      uVar5 = puVar24[3];
                      *(int *)(lVar18 + 0xebc) = *(int *)(lVar18 + 0xebc) + -1;
                      *(undefined8 *)(lVar18 + 0xe20) = uVar5;
                      *puVar24 = 1;
                    }
                    pcVar22 = _PyRuntime_exref;
                    pcStack_118 = _PyRuntime_exref;
                    lVar18 = *(longlong *)
                              (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8
                              );
                    uVar5 = puVar24[-1];
                    puVar6 = *(undefined8 **)(lVar18 + 8);
                    *puVar6 = puVar24 + -2;
                    puVar24[-2] = lVar18;
                    puVar24[-1] = (ulonglong)((uint)uVar5 & 3) | (ulonglong)puVar6;
                    *(undefined8 **)(lVar18 + 8) = puVar24 + -2;
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                    puVar24[3] = pcVar15;
                    *plVar17 = *plVar17 + 1;
                    puVar24[4] = plVar17;
                    pcVar19 = (code *)FUN_23ebf8230(param_1);
                    if (pcVar19 == (code *)0x0) {
                      uStack_98 = *(undefined8 *)(param_1 + 0x60);
                      uStack_90 = *(undefined8 *)(param_1 + 0x68);
                      plVar20 = *(longlong **)(param_1 + 0x70);
                      pcStack_120._0_4_ = 0x7d;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      iVar14 = PySequence_Contains(plVar17,_DAT_23ee07670);
                      if (iVar14 == -1) {
                        uStack_98 = *(undefined8 *)(param_1 + 0x60);
                        uStack_90 = *(undefined8 *)(param_1 + 0x68);
                        plVar20 = *(longlong **)(param_1 + 0x70);
                        pcStack_120._0_4_ = 0x7f;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        if (iVar14 != 1) {
LAB_23c04d3fd:
                          *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                          uVar5 = DAT_23ee075f8;
                          *(undefined4 *)(plVar4 + 5) = 0x7b;
                          plVar20 = (longlong *)FUN_23e957a30(param_1,in_R11,uVar5);
                          if (plVar20 == (longlong *)0x0) {
                            pcStack_120 = _Py_NoneStruct_exref;
                            pcVar27 = *(code **)(param_1 + 0x70);
                            pcStack_118._0_4_ = 0x7b;
                            pcVar22 = *(code **)(param_1 + 0x60);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pcVar23 = *(code **)(param_1 + 0x68);
                            pcVar10 = pcStack_78;
                            pcVar11 = pcStack_70;
                            pcVar12 = pcStack_68;
                            goto LAB_23c04e1f5;
                          }
                          *plVar20 = *plVar20 + -1;
                          if (*plVar20 == 0) {
                            (**(code **)(plVar20[1] + 0x30))(plVar20);
                          }
                          lVar18 = *(longlong *)pcStack_128;
                          *(longlong *)pcStack_128 = lVar18 + -1;
                          if (lVar18 + -1 == 0) {
                            (**(code **)(*(longlong *)((longlong)pcStack_128 + 8) + 0x30))
                                      (pcStack_128);
                          }
                          lVar18 = *plVar16;
                          *plVar16 = lVar18 + -1;
                          if (lVar18 + -1 == 0) {
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          *in_R11 = *in_R11 + -1;
                          pcVar22 = pcVar19;
                          if (*in_R11 == 0) {
                            (**(code **)(in_R11[1] + 0x30))(in_R11);
                          }
                          goto LAB_23c04d09b;
                        }
                        lVar18 = FUN_23e913e30(param_1,pcVar15,_DAT_23ee07670);
                        if (lVar18 != 0) {
                          lVar3 = *(longlong *)(param_1 + 0x10);
                          plVar21 = *(longlong **)(lVar3 + 0xe20);
                          if (plVar21 == (longlong *)0x0) {
                            plVar21 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                          }
                          else {
                            lVar7 = plVar21[3];
                            *(int *)(lVar3 + 0xebc) = *(int *)(lVar3 + 0xebc) + -1;
                            *(longlong *)(lVar3 + 0xe20) = lVar7;
                            *plVar21 = 1;
                          }
                          plVar21[4] = 0;
                          lVar3 = *(longlong *)
                                   (*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
                          lVar7 = plVar21[-1];
                          puVar24 = *(undefined8 **)(lVar3 + 8);
                          *puVar24 = plVar21 + -2;
                          plVar21[-2] = lVar3;
                          plVar21[-1] = (ulonglong)((uint)lVar7 & 3) | (ulonglong)puVar24;
                          *(longlong **)(lVar3 + 8) = plVar21 + -2;
                          plVar21[3] = lVar18;
                          lVar18 = FUN_23a38cc10(param_1,plVar17);
                          if (lVar18 == 0) {
                            uStack_98 = *(undefined8 *)(param_1 + 0x60);
                            uStack_90 = *(undefined8 *)(param_1 + 0x68);
                            plVar20 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pcStack_120._0_4_ = 0x80;
                            *plVar21 = *plVar21 + -1;
                            if (*plVar21 == 0) {
                              FUN_23a334bc0(plVar21);
                              pcStack_120._0_4_ = 0x80;
                            }
                            goto LAB_23c04e363;
                          }
                          plVar21[4] = lVar18;
                          plVar20 = (longlong *)FUN_23ebf8230(param_1,plVar21);
                          if (plVar20 != (longlong *)0x0) {
                            cVar13 = FUN_23a39bc50(param_1,pcVar19,_DAT_23ee07670,plVar20);
                            *plVar20 = *plVar20 + -1;
                            if (*plVar20 == 0) {
                              FUN_23a334bc0(plVar20);
                            }
                            if (cVar13 != '\0') goto LAB_23c04d3fd;
                          }
                        }
                        uStack_98 = *(undefined8 *)(param_1 + 0x60);
                        plVar20 = *(longlong **)(param_1 + 0x70);
                        pcStack_120._0_4_ = 0x80;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uStack_90 = *(undefined8 *)(param_1 + 0x68);
                      }
                    }
                  }
                }
LAB_23c04e363:
                plVar21 = *(longlong **)(param_1 + 0x138);
                auStack_b8._8_8_ = uStack_90;
                auStack_b8._0_8_ = uStack_98;
                if (plVar21 != (longlong *)0x0) {
                  *plVar21 = *plVar21 + 1;
                }
                pcVar23 = DAT_23ed6a4f8;
                pcStack_a8 = (code *)plVar20;
                if (plVar20 == (longlong *)0x0) {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar22 = *(code **)DAT_23ed6a4f8;
                    *(longlong *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar22;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  *(longlong *)(pcVar23 + 0x10) = 0;
                  *(longlong **)(pcVar23 + 0x18) = plVar4;
                  *plVar4 = *plVar4 + 1;
                  lVar18 = *(longlong *)(pcStack_118 + 0x1f8);
                  *(undefined4 *)(pcVar23 + 0x24) = pcStack_120._0_4_;
                  lVar18 = *(longlong *)(lVar18 + 0x10);
                  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
                  lVar18 = *(longlong *)(lVar18 + 0x2e8);
                  lVar3 = *(longlong *)(pcVar23 + -8);
                  puVar24 = *(undefined8 **)(lVar18 + 8);
                  *puVar24 = pcVar23 + -0x10;
                  *(longlong *)(pcVar23 + -0x10) = lVar18;
                  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar24;
                  *(code **)(lVar18 + 8) = pcVar23 + -0x10;
                  if ((pcStack_a8 != (code *)0x0) &&
                     (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1,
                     *(longlong *)pcStack_a8 == 0)) {
                    (**(code **)(*(longlong *)((longlong)pcStack_a8 + 8) + 0x30))(pcStack_a8);
                  }
                }
                else {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar22 = *(code **)DAT_23ed6a4f8;
                    *(longlong *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar22;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  *(longlong **)(pcVar23 + 0x18) = plVar4;
                  *plVar4 = *plVar4 + 1;
                  lVar18 = *(longlong *)(pcStack_118 + 0x1f8);
                  *(undefined4 *)(pcVar23 + 0x24) = pcStack_120._0_4_;
                  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
                  lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
                  lVar3 = *(longlong *)(pcVar23 + -8);
                  puVar24 = *(undefined8 **)(lVar18 + 8);
                  *puVar24 = pcVar23 + -0x10;
                  *(longlong *)(pcVar23 + -0x10) = lVar18;
                  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar24;
                  *(code **)(lVar18 + 8) = pcVar23 + -0x10;
                  *(longlong **)(pcVar23 + 0x10) = plVar20;
                  *plVar20 = *plVar20 + 1;
                  if ((pcStack_a8 != (code *)0x0) &&
                     (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1,
                     *(longlong *)pcStack_a8 == 0)) {
                    (**(code **)(*(longlong *)((longlong)pcStack_a8 + 8) + 0x30))();
                  }
                }
                pcVar22 = _Py_NoneStruct_exref;
                pcStack_120 = _Py_NoneStruct_exref;
                pcStack_a8 = pcVar23;
                if (((code *)auStack_b8._0_8_ != _Py_NoneStruct_exref) &&
                   ((code *)auStack_b8._0_8_ != (code *)0x0)) {
                  FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8);
                }
                plVar20 = *(longlong **)(auStack_b8._8_8_ + 0x28);
                if (pcStack_a8 == pcVar22) {
                  pcVar23 = (code *)0x0;
                }
                else {
                  pcVar23 = pcStack_a8;
                  if (pcStack_a8 != (code *)0x0) {
                    *(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + 1;
                  }
                }
                *(code **)(auStack_b8._8_8_ + 0x28) = pcVar23;
                if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                  (**(code **)(plVar20[1] + 0x30))();
                }
                plVar20 = *(longlong **)(param_1 + 0x138);
                *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
                if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                  (**(code **)(plVar20[1] + 0x30))();
                }
                *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
                if (*(longlong *)auStack_b8._0_8_ == 0) {
                  (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
                }
                if ((pcStack_a8 != (code *)0x0) &&
                   (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1,
                   *(longlong *)pcStack_a8 == 0)) {
                  (**(code **)(*(longlong *)(pcStack_a8 + 8) + 0x30))();
                }
                pcStack_a8 = (code *)0x0;
                auStack_b8 = (undefined1  [16])0x0;
                iVar14 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                       *(undefined8 *)PyExc_BaseException_exref);
                pcVar23 = *(code **)(param_1 + 0x138);
                if (iVar14 == 0) {
                  if ((pcVar23 != pcVar22) && (pcVar23 != (code *)0x0)) {
                    pcVar22 = *(code **)(pcVar23 + 8);
                    pcVar27 = *(code **)(pcVar23 + 0x28);
                    *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                    if ((pcVar27 != (code *)0x0) &&
                       (*(longlong *)pcVar27 = *(longlong *)pcVar27 + 1,
                       plVar4 == *(longlong **)(pcVar27 + 0x18))) {
                      *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar27 + 0x24);
                    }
                    *(longlong **)(param_1 + 0x138) = plVar21;
                    bVar9 = true;
                    pcStack_118._0_4_ = 0;
                    pcVar25 = pcVar23;
                    goto LAB_23c04e6a0;
                  }
                  pcVar22 = *(code **)PyExc_RuntimeError_exref;
                  pcVar23 = (code *)PyUnicode_FromString("No active exception to reraise");
                  pcVar25 = *(code **)(param_1 + 0x138);
                  *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                  *(longlong **)(param_1 + 0x138) = plVar21;
                  if (pcVar25 != (code *)0x0) {
                    pcStack_118._0_4_ = 0x7b;
                    pcVar27 = (code *)0x0;
                    bVar9 = true;
                    goto LAB_23c04e6a0;
                  }
                  pcStack_68 = (code *)0x0;
                  pcStack_118._0_4_ = 0x7b;
                  pcStack_78 = pcVar22;
                  pcStack_70 = pcVar23;
                  goto LAB_23c04ea72;
                }
                pcStack_78 = *(code **)(pcVar23 + 8);
                pcStack_68 = *(code **)(pcVar23 + 0x28);
                *(undefined4 *)(plVar4 + 5) = 0x7b;
                if (pcStack_68 == (code *)0x0) {
                  pcStack_68 = pcVar22;
                }
                pcStack_70 = pcVar23;
                plVar20 = (longlong *)FUN_23e956150(param_1,in_R11,&pcStack_78);
                if (plVar20 == (longlong *)0x0) {
                  pcVar27 = *(code **)(param_1 + 0x70);
                  pcVar22 = *(code **)(param_1 + 0x60);
                  pcVar23 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c04e8a7;
                }
                iVar14 = FUN_23a35f020(plVar20);
                *plVar20 = *plVar20 + -1;
                if (*plVar20 == 0) {
                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                }
                if (iVar14 == -1) goto LAB_23c04ebee;
                if (iVar14 == 0) {
                  pcVar23 = *(code **)(param_1 + 0x138);
                  bVar9 = false;
                  if ((pcVar23 == pcVar22) || (pcVar23 == (code *)0x0)) {
                    pcVar22 = *(code **)PyExc_RuntimeError_exref;
                    pcVar23 = (code *)PyUnicode_FromString("No active exception to reraise");
                    pcStack_118._0_4_ = 0x7b;
                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                  }
                  else {
                    pcVar22 = *(code **)(pcVar23 + 8);
                    pcVar27 = *(code **)(pcVar23 + 0x28);
                    *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                    if (pcVar27 != (code *)0x0) {
                      *(longlong *)pcVar27 = *(longlong *)pcVar27 + 1;
                      if (plVar4 == *(longlong **)(pcVar27 + 0x18)) {
                        *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar27 + 0x24);
                      }
                      *(longlong **)(param_1 + 0x138) = plVar21;
                      pcStack_118._0_4_ = 0;
                      pcVar25 = pcVar23;
                      goto LAB_23c04e6a0;
                    }
                    pcStack_118._0_4_ = 0;
                  }
                  pcVar25 = *(code **)(param_1 + 0x138);
                  pcVar27 = (code *)0x0;
                  *(longlong **)(param_1 + 0x138) = plVar21;
                  if (pcVar25 != (code *)0x0) goto LAB_23c04e6a0;
                  pcStack_68 = (code *)0x0;
                  pcVar27 = pcStack_68;
                  pcVar10 = pcVar22;
                  pcVar11 = pcVar23;
                  pcVar12 = pcStack_68;
                  goto LAB_23c04e1f5;
                }
                plVar4 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar21;
                if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
                lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar4 = *(longlong **)(lVar18 + 0x28);
                plVar20 = (longlong *)plVar4[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
                *(undefined4 *)(plVar4 + 8) = 0xffffffff;
                if (plVar20 != (longlong *)0x0) {
                  plVar4[2] = 0;
                  *plVar20 = *plVar20 + -1;
                  if (*plVar20 == 0) {
                    (**(code **)(plVar20[1] + 0x30))();
                  }
                }
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))(plVar4);
                }
                plVar4[0xf] = 0;
                lVar18 = *(longlong *)pcStack_128;
                *(longlong *)pcStack_128 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(*(longlong *)((longlong)pcStack_128 + 8) + 0x30))(pcStack_128);
                }
                lVar18 = *plVar16;
                *plVar16 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                *in_R11 = *in_R11 + -1;
                if (*in_R11 == 0) {
                  (**(code **)(in_R11[1] + 0x30))(in_R11);
                }
                *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                if (*(longlong *)pcVar15 == 0) {
                  (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                }
                goto LAB_23c04d0ff;
              }
            }
            pauVar1 = (undefined1 (*) [16])(param_1 + 0x60);
            pcVar22 = *(code **)*pauVar1;
            auVar8 = *pauVar1;
            auStack_d8 = *pauVar1;
            pcVar27 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            lVar18 = *(longlong *)pcStack_128;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(longlong *)pcStack_128 = lVar18 + -1;
            apcStack_c8[0] = pcVar27;
            if (lVar18 + -1 != 0) {
              plStack_110 = *(longlong **)(param_1 + 0x138);
              goto joined_r0x00023c04de70;
            }
            (**(code **)(*(longlong *)((longlong)pcStack_128 + 8) + 0x30))(pcStack_128);
            plStack_110 = *(longlong **)(param_1 + 0x138);
            auStack_d8 = auVar8;
            if (plStack_110 != (longlong *)0x0) {
              plVar16 = (longlong *)0x0;
              plVar17 = (longlong *)0x0;
              pcStack_118._0_4_ = 0x7b;
              pcVar19 = (code *)0x0;
              pcStack_120 = _Py_NoneStruct_exref;
              goto LAB_23c04dd20;
            }
          }
          if (apcStack_c8[0] == (code *)0x0) {
LAB_23c04eac8:
            pcStack_120 = _Py_NoneStruct_exref;
            plVar16 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            pcVar19 = (code *)0x0;
            plStack_110 = (longlong *)0x0;
            uVar26 = 0x7b;
            goto LAB_23c04d976;
          }
        }
        pcVar19 = (code *)0x0;
        plVar16 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        pcStack_120 = _Py_NoneStruct_exref;
LAB_23c04d55c:
        pcVar22 = apcStack_c8[0];
        pcVar23 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar27 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar27;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar23 + 0x18) = plVar4;
        *plVar4 = *plVar4 + 1;
        *(longlong *)(pcVar23 + 0x20) = 0x7bffffffff;
        lVar18 = *(longlong *)
                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = *(longlong *)(pcVar23 + -8);
        in_R11 = *(longlong **)(lVar18 + 8);
        *in_R11 = (longlong)(pcVar23 + -0x10);
        *(longlong *)(pcVar23 + -0x10) = lVar18;
        *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)in_R11;
        *(code **)(lVar18 + 8) = pcVar23 + -0x10;
        *(code **)(pcVar23 + 0x10) = pcVar22;
        *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
        pcVar22 = apcStack_c8[0];
joined_r0x00023c04d5ec:
        if ((pcVar22 != (code *)0x0) &&
           (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
          (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
        }
        pcVar22 = (code *)auStack_d8._0_8_;
        apcStack_c8[0] = pcVar23;
        do {
          if ((pcVar22 != (code *)0x0) && (pcVar22 != pcStack_120)) {
            FUN_23e91b1b0(param_1,auStack_d8,auStack_d8 + 8,apcStack_c8);
          }
          plVar20 = *(longlong **)(auStack_d8._8_8_ + 0x28);
          if (apcStack_c8[0] == pcStack_120) {
            pcVar22 = (code *)0x0;
          }
          else {
            pcVar22 = apcStack_c8[0];
            if (apcStack_c8[0] != (code *)0x0) {
              *(longlong *)apcStack_c8[0] = *(longlong *)apcStack_c8[0] + 1;
            }
          }
          *(code **)(auStack_d8._8_8_ + 0x28) = pcVar22;
          if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
            (**(code **)(plVar20[1] + 0x30))();
          }
          plVar20 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = auStack_d8._8_8_;
          if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
            (**(code **)(plVar20[1] + 0x30))();
          }
          *(longlong *)auStack_d8._0_8_ = *(longlong *)auStack_d8._0_8_ + -1;
          if (*(longlong *)auStack_d8._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_d8._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_c8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_c8[0] = *(longlong *)apcStack_c8[0] + -1,
             *(longlong *)apcStack_c8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_c8[0] + 8) + 0x30))();
          }
          apcStack_c8[0] = (code *)0x0;
          auStack_d8 = (undefined1  [16])0x0;
          iVar14 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                 *(undefined8 *)PyExc_Exception_exref);
          pcVar23 = *(code **)(param_1 + 0x138);
          if (iVar14 == 0) {
            if ((pcVar23 == pcStack_120) || (pcVar23 == (code *)0x0)) {
              pcStack_120 = *(code **)PyExc_RuntimeError_exref;
              pcStack_128 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar23 = *(code **)(param_1 + 0x138);
              *(longlong *)pcStack_120 = *(longlong *)pcStack_120 + 1;
              *(longlong **)(param_1 + 0x138) = plStack_110;
              if ((pcVar23 == (code *)0x0) ||
                 (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 != 0)) {
                iVar14 = 0x7a;
                pcStack_118 = _PyRuntime_exref;
                goto LAB_23c04dfd7;
              }
              pcVar22 = (code *)0x0;
              iVar14 = 0x7a;
LAB_23c04e0b6:
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
              if (pcVar22 == (code *)0x0) {
                if (iVar14 != 0) goto LAB_23c04e2ee;
LAB_23c04e0e3:
                pcStack_118 = _PyRuntime_exref;
                iVar14 = (int)plVar4[5];
                goto LAB_23c04dfd7;
              }
LAB_23c04de0b:
              pcVar23 = pcVar22;
              if (plVar4 == *(longlong **)(pcVar22 + 0x18)) goto LAB_23c04db00;
              if (iVar14 != 0) goto LAB_23c04d1b8;
            }
            else {
              pcStack_120 = *(code **)(pcVar23 + 8);
              pcVar22 = *(code **)(pcVar23 + 0x28);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              *(longlong *)pcStack_120 = *(longlong *)pcStack_120 + 1;
              iVar14 = 0;
              pcStack_128 = pcVar23;
              if (pcVar22 == (code *)0x0) {
                *(longlong **)(param_1 + 0x138) = plStack_110;
                lVar18 = *(longlong *)pcVar23;
                *(longlong *)pcVar23 = lVar18 + -1;
                if (lVar18 + -1 == 0) goto LAB_23c04e0b6;
                goto LAB_23c04e0e3;
              }
              *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
              if (plVar4 == *(longlong **)(pcVar22 + 0x18)) {
                *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar22 + 0x24);
              }
              *(longlong **)(param_1 + 0x138) = plStack_110;
              lVar18 = *(longlong *)pcVar23;
              *(longlong *)pcVar23 = lVar18 + -1;
              if (lVar18 + -1 == 0) {
                (**(code **)((longlong)pcStack_120 + 0x30))();
                goto LAB_23c04de0b;
              }
              pcVar23 = pcVar22;
              if (plVar4 == *(longlong **)(pcVar22 + 0x18)) goto LAB_23c04db00;
            }
            pcStack_118 = _PyRuntime_exref;
            iVar14 = (int)plVar4[5];
            goto LAB_23c04da68;
          }
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
          pcStack_120 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
          plVar20 = _DAT_23ee07678;
          lVar18 = *(longlong *)(param_1 + 0x10);
          pcStack_128 = *(code **)(lVar18 + 0xe20);
          if (pcStack_128 == (code *)0x0) {
            pcStack_128 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar3 = *(longlong *)((longlong)pcStack_128 + 0x18);
            *(int *)(lVar18 + 0xebc) = *(int *)(lVar18 + 0xebc) + -1;
            *(longlong *)(lVar18 + 0xe20) = lVar3;
            *(longlong *)pcStack_128 = 1;
          }
          pcStack_118 = _PyRuntime_exref;
          *(longlong *)((longlong)pcStack_128 + 0x20) = 0;
          lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_118 + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = *(longlong *)((longlong)pcStack_128 + -8);
          puVar24 = *(undefined8 **)(lVar18 + 8);
          *puVar24 = (longlong *)((longlong)pcStack_128 + -0x10);
          *(longlong *)((longlong)pcStack_128 + -0x10) = lVar18;
          *(ulonglong *)((longlong)pcStack_128 + -8) =
               (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar24;
          *(longlong **)(lVar18 + 8) = (longlong *)((longlong)pcStack_128 + -0x10);
          plVar21 = DAT_23ed6a4c0;
          *plVar20 = *plVar20 + 1;
          *(longlong **)((longlong)pcStack_128 + 0x18) = plVar20;
          uVar5 = DAT_23ed6cd28;
          if (plVar21 != (longlong *)0x0) {
LAB_23c04d7e7:
            uStack_e0 = uVar5;
            pcStack_e8 = pcVar23;
            lVar18 = FUN_23e94ed00(param_1,plVar21,&pcStack_e8);
            if (lVar18 == 0) {
              pcStack_120 = *(code **)(param_1 + 0x60);
              pcVar22 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar27 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
              if (*(longlong *)pcStack_128 == 0) {
                (**(code **)(*(longlong *)((longlong)pcStack_128 + 8) + 0x30))(pcStack_128);
              }
            }
            else {
              *(longlong *)((longlong)pcStack_128 + 0x20) = lVar18;
              plVar20 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcStack_128);
              *(longlong *)pcStack_128 = *(longlong *)pcStack_128 + -1;
              if (*(longlong *)pcStack_128 == 0) {
                (**(code **)(*(longlong *)((longlong)pcStack_128 + 8) + 0x30))(pcStack_128);
              }
              if (plVar20 != (longlong *)0x0) {
                *(undefined4 *)(plVar4 + 5) = 0x83;
                plVar21 = (longlong *)FUN_23e914090(param_1,pcStack_120,plVar20);
                *plVar20 = *plVar20 + -1;
                if (*plVar20 == 0) {
                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                }
                if (plVar21 != (longlong *)0x0) {
                  *plVar21 = *plVar21 + -1;
                  if (*plVar21 == 0) {
                    (**(code **)(plVar21[1] + 0x30))(plVar21);
                  }
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                  lVar18 = *(longlong *)pcVar23;
                  *(longlong *)pcVar23 = lVar18 + -1;
                  if (lVar18 + -1 == 0) {
                    (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
                  }
                  plVar4 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plStack_110;
                  pcVar22 = pcVar15;
                  if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
                    (**(code **)(plVar4[1] + 0x30))();
                  }
                  goto LAB_23c04d09b;
                }
              }
              pcStack_120 = *(code **)(param_1 + 0x60);
              pcVar22 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar27 = *(code **)(param_1 + 0x68);
            }
            pcStack_128 = pcVar27;
            lVar18 = *(longlong *)pcVar23;
            *(longlong *)pcVar23 = lVar18 + -1;
            if (lVar18 + -1 == 0) {
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
            }
            pcVar23 = *(code **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plStack_110;
            if (pcVar23 == (code *)0x0) {
              if (pcVar22 == (code *)0x0) {
LAB_23c04eaef:
                iVar14 = 0x83;
                goto LAB_23c04dfd7;
              }
              plVar20 = *(longlong **)(pcVar22 + 0x18);
            }
            else {
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                iVar14 = 0x83;
                goto LAB_23c04e0b6;
              }
              if (pcVar22 == (code *)0x0) goto LAB_23c04eaef;
              plVar20 = *(longlong **)(pcVar22 + 0x18);
            }
            pcVar23 = pcVar22;
            if (plVar20 == plVar4) goto LAB_23c04db00;
            iVar14 = 0x83;
            goto LAB_23c04da68;
          }
          plVar21 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar21 != (longlong *)0x0) {
            *plVar21 = *plVar21 + 1;
            DAT_23ed6a4c0 = plVar21;
            goto LAB_23c04d7e7;
          }
          PyErr_PrintEx(0);
          Py_Exit(1);
          plVar21 = plVar16;
LAB_23c04ebee:
          pcVar22 = *(code **)(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x68);
          pcVar27 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c04e8a7:
          pcVar25 = *(code **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x70) = 0;
          bVar9 = false;
          *(longlong **)(param_1 + 0x138) = plVar21;
          pcStack_118._0_4_ = 0x7b;
          plVar16 = plStack_110;
          pcVar10 = pcVar22;
          pcVar11 = pcVar23;
          pcVar12 = pcVar27;
          if (pcVar25 != (code *)0x0) {
LAB_23c04e6a0:
            *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
            if (*(longlong *)pcVar25 == 0) {
              (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))();
            }
            plVar16 = plStack_110;
            pcStack_78 = pcVar22;
            pcVar10 = pcVar22;
            pcStack_70 = pcVar23;
            pcVar11 = pcVar23;
            pcStack_68 = pcVar27;
            pcVar12 = pcVar27;
            if (bVar9) {
LAB_23c04ea72:
              *(undefined4 *)(plVar4 + 5) = 0x7b;
              plVar20 = (longlong *)FUN_23e957a30(param_1,in_R11,DAT_23ee075f8);
              plVar16 = plStack_110;
              if (plVar20 == (longlong *)0x0) {
                pcVar27 = *(code **)(param_1 + 0x70);
                pcVar22 = *(code **)(param_1 + 0x60);
                pcVar23 = *(code **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                FUN_23a35d6b0(&pcStack_78);
                pcStack_118._0_4_ = 0x7b;
                pcVar10 = pcStack_78;
                pcVar11 = pcStack_70;
                pcVar12 = pcStack_68;
              }
              else {
                *plVar20 = *plVar20 + -1;
                pcVar27 = pcStack_68;
                pcVar22 = pcStack_78;
                pcVar23 = pcStack_70;
                pcVar10 = pcStack_78;
                pcVar11 = pcStack_70;
                pcVar12 = pcStack_68;
                if (*plVar20 == 0) {
                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                  pcVar27 = pcStack_68;
                  pcVar22 = pcStack_78;
                  pcVar23 = pcStack_70;
                  pcVar10 = pcStack_78;
                  pcVar11 = pcStack_70;
                  pcVar12 = pcStack_68;
                }
              }
            }
          }
LAB_23c04e1f5:
          pcStack_68 = pcVar12;
          pcStack_70 = pcVar11;
          pcStack_78 = pcVar10;
          lVar18 = *(longlong *)pcStack_128;
          *(longlong *)pcStack_128 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            (**(code **)(*(longlong *)((longlong)pcStack_128 + 8) + 0x30))();
          }
          lVar18 = *plStack_110;
          *plStack_110 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            (**(code **)(plStack_110[1] + 0x30))();
          }
          if ((in_R11 != (longlong *)0x0) && (*in_R11 = *in_R11 + -1, *in_R11 == 0)) {
            (**(code **)(in_R11[1] + 0x30))(in_R11);
          }
          plStack_110 = *(longlong **)(param_1 + 0x138);
          auStack_d8._8_8_ = pcVar23;
          auStack_d8._0_8_ = pcVar22;
          apcStack_c8[0] = pcVar27;
          if (plStack_110 != (longlong *)0x0) {
LAB_23c04dd20:
            *plStack_110 = *plStack_110 + 1;
            apcStack_c8[0] = pcVar27;
          }
          if (apcStack_c8[0] == (code *)0x0) goto LAB_23c04e140;
          if ((int)pcStack_118 != 0) goto LAB_23c04d55c;
        } while( true );
      }
      pcStack_120 = *(code **)(param_1 + 0x60);
      pcVar22 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_128 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar22 == (code *)0x0) {
        pcVar19 = (code *)0x0;
        plVar17 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        iVar14 = 0x77;
LAB_23c04e2ee:
        pcStack_118 = _PyRuntime_exref;
        goto LAB_23c04dfd7;
      }
      if (*(longlong **)(pcVar22 + 0x18) == plVar4) {
        pcVar19 = (code *)0x0;
        plVar17 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        pcVar23 = pcVar22;
        goto LAB_23c04db00;
      }
      pcVar19 = (code *)0x0;
      plVar17 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      iVar14 = 0x77;
      pcStack_118 = _PyRuntime_exref;
    }
  }
LAB_23c04da68:
  pcVar23 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar27 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar27;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar23 + 0x18) = plVar4;
  *plVar4 = *plVar4 + 1;
  lVar18 = *(longlong *)(pcStack_118 + 0x1f8);
  *(int *)(pcVar23 + 0x24) = iVar14;
  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
  lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
  lVar3 = *(longlong *)(pcVar23 + -8);
  puVar24 = *(undefined8 **)(lVar18 + 8);
  *puVar24 = pcVar23 + -0x10;
  *(longlong *)(pcVar23 + -0x10) = lVar18;
  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar24;
  lVar3 = *(longlong *)pcVar22;
  *(code **)(lVar18 + 8) = pcVar23 + -0x10;
  *(code **)(pcVar23 + 0x10) = pcVar22;
  if (lVar3 == 0) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
LAB_23c04db00:
  FUN_23e8bba40(plVar4,"oooooo",plVar2,pcVar15,plVar16,plVar17,pcVar19,0);
  if (_DAT_23ee0b600 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23ee0b600 = (longlong *)0x0;
  }
  lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar18 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
  plVar20 = (longlong *)plVar4[2];
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar20 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
  if (*(longlong *)pcVar15 == 0) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((pcVar19 != (code *)0x0) &&
     (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,pcStack_120,pcStack_128,pcVar23);
  return (code *)0x0;
LAB_23c04e140:
  if ((int)pcStack_118 == 0) {
    uVar26 = (undefined4)plVar4[5];
  }
  else {
    uVar26 = 0x7b;
  }
LAB_23c04d976:
  pcVar23 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar22 = apcStack_c8[0];
  }
  else {
    pcVar22 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar22;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar22 = (code *)0x0;
  }
  pcVar27 = _PyRuntime_exref;
  *(longlong *)(pcVar23 + 0x10) = 0;
  *(longlong **)(pcVar23 + 0x18) = plVar4;
  *plVar4 = *plVar4 + 1;
  lVar18 = *(longlong *)(pcVar27 + 0x1f8);
  *(undefined4 *)(pcVar23 + 0x24) = uVar26;
  lVar18 = *(longlong *)(lVar18 + 0x10);
  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
  lVar18 = *(longlong *)(lVar18 + 0x2e8);
  lVar3 = *(longlong *)(pcVar23 + -8);
  puVar24 = *(undefined8 **)(lVar18 + 8);
  *puVar24 = pcVar23 + -0x10;
  *(longlong *)(pcVar23 + -0x10) = lVar18;
  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar24;
  *(code **)(lVar18 + 8) = pcVar23 + -0x10;
  goto joined_r0x00023c04d5ec;
}
