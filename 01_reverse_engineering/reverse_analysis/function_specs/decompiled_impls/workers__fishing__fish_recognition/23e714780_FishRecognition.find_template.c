/* ===== 23e714780 workers.fishing.fish_recognition:184 ===== */
/* ghidra_name=FUN_23e714780 entry=23e714780 size=8553 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_23e714780(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  code *pcVar9;
  code *pcVar10;
  undefined1 auVar11 [16];
  longlong *plVar12;
  char cVar13;
  int iVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong *plVar22;
  undefined8 *puVar23;
  undefined4 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_b8;
  undefined1 auStack_98 [16];
  longlong *plStack_88;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar18 = _DAT_23eedb090;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  plStack_88 = (longlong *)0x0;
  plVar4 = (longlong *)param_3[3];
  auStack_98 = (undefined1  [16])0x0;
  if (_DAT_23eedb090 == (longlong *)0x0) {
LAB_23e714801:
    _DAT_23eedb090 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb088,DAT_23eedb148,0x70);
  }
  else {
    lVar15 = *_DAT_23eedb090;
    if (1 < lVar15) {
      *_DAT_23eedb090 = lVar15 + -1;
      goto LAB_23e714801;
    }
    if (_DAT_23eedb090[2] != 0) {
      *_DAT_23eedb090 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      goto LAB_23e714801;
    }
  }
  plVar6 = _DAT_23eedb090;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar18 = _DAT_23eedb090 + 9;
  lVar5 = *(longlong *)(lVar15 + 8);
  _DAT_23eedb090[0xf] = lVar5;
  *(longlong **)(lVar15 + 8) = plVar18;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar18 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar18;
    if (plVar18 != (longlong *)0x0) {
      *plVar18 = *plVar18 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  iVar14 = FUN_23a35f020(plVar4);
  if (iVar14 == -1) {
    plStack_88 = *(longlong **)(param_1 + 0x70);
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    uVar24 = 0xbe;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    if (iVar14 == 0) {
      *plVar2 = *plVar2 + 1;
      plVar20 = plVar2;
LAB_23e7148a9:
      lVar15 = FUN_23e8e11f0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eed9e40);
        plVar18 = (longlong *)0x0;
LAB_23e715189:
        plStack_b8 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        uVar24 = 200;
        plStack_c8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        goto LAB_23e7151e0;
      }
      plVar16 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eeda018);
      if (plVar16 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar18 = (longlong *)0x0;
        uVar24 = 200;
        plStack_b8 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar16 = (longlong *)0x0;
        goto LAB_23e7151e0;
      }
      lVar15 = FUN_23e8e11f0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eed9e40);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        plVar18 = (longlong *)0x0;
        goto LAB_23e715189;
      }
      plVar17 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eeda020);
      if (plVar17 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        plStack_b8 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plVar18 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        uVar24 = 200;
        plStack_c8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        goto LAB_23e7151e0;
      }
      *(undefined4 *)(plVar6 + 5) = 200;
      plStack_78 = plVar20;
      plStack_70 = plVar3;
      plStack_68 = plVar17;
      plVar18 = (longlong *)FUN_23e956150(param_1,plVar16,&plStack_78);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
      if (plVar18 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e715189;
      }
      lVar15 = FUN_23e8e11f0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eed9e40);
        plVar21 = plStack_88;
        uVar25 = auStack_98._0_8_;
        uVar26 = auStack_98._8_8_;
      }
      else {
        *(undefined4 *)(plVar6 + 5) = 0xc9;
        plVar16 = (longlong *)FUN_23e915840(param_1,lVar15,_DAT_23eeda028,plVar18);
        if (plVar16 != (longlong *)0x0) {
          plVar19 = (longlong *)FUN_23a388310(plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (plVar19 != (longlong *)0x0) {
            plVar17 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
            if ((plVar17 == (longlong *)0x0) &&
               (plVar17 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4),
               plVar17 == (longlong *)0x0)) {
              plStack_e0 = (longlong *)0x0;
              plVar16 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
            }
            else {
              plVar16 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
              if ((plVar16 == (longlong *)0x0) &&
                 (plVar16 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,4),
                 plVar16 == (longlong *)0x0)) {
                plStack_e0 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
              }
              else {
                plStack_e8 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
                if ((plStack_e8 == (longlong *)0x0) &&
                   (plStack_e8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,4),
                   plStack_e8 == (longlong *)0x0)) {
                  plStack_e0 = (longlong *)0x0;
                }
                else {
                  plStack_e0 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
                  if (((plStack_e0 != (longlong *)0x0) ||
                      (plStack_e0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,3,4),
                      plStack_e0 != (longlong *)0x0)) &&
                     (cVar13 = FUN_23a3884a0(param_1,auStack_98,plVar19,4), cVar13 != '\0')) {
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      (**(code **)(plVar19[1] + 0x30))(plVar19);
                    }
                    if (*plVar17 == 0) {
                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                    }
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    if (*plStack_e8 == 0) {
                      (**(code **)(plStack_e8[1] + 0x30))();
                    }
                    if (*plStack_e0 == 0) {
                      (**(code **)(plStack_e0[1] + 0x30))();
                    }
                    lVar15 = *(longlong *)(DAT_23eed9ce8 + 0x20);
                    if (*(char *)(lVar15 + 10) == '\0') {
                      plVar19 = (longlong *)FUN_23a37a020(DAT_23eed9ce8,_DAT_23eeda030);
                      if (plVar19 == (longlong *)0x0) goto LAB_23e715d80;
                      lVar15 = *plVar19;
LAB_23e715d71:
                      if (lVar15 == 0) goto LAB_23e715d80;
LAB_23e714b27:
                      iVar14 = FUN_23e97d0c0(plVar16);
                      if (iVar14 != -1) {
                        if (iVar14 != 1) {
                          lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar6 = *(longlong **)(lVar15 + 0x28);
                          plVar19 = (longlong *)plVar6[2];
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar15 + 0x30);
                          *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                          if (plVar19 != (longlong *)0x0) {
                            plVar6[2] = 0;
                            *plVar19 = *plVar19 + -1;
                            if (*plVar19 == 0) {
                              (**(code **)(plVar19[1] + 0x30))();
                            }
                          }
                          *plVar6 = *plVar6 + -1;
                          if (*plVar6 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          lVar15 = *(longlong *)(param_1 + 0x10);
                          plVar6[0xf] = 0;
                          puVar23 = *(undefined8 **)(lVar15 + 0xe30);
                          if (puVar23 == (undefined8 *)0x0) {
                            puVar23 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,4);
                          }
                          else {
                            uVar25 = puVar23[3];
                            *(int *)(lVar15 + 0xec4) = *(int *)(lVar15 + 0xec4) + -1;
                            *(undefined8 *)(lVar15 + 0xe30) = uVar25;
                            *puVar23 = 1;
                          }
                          plStack_b8 = (longlong *)0x0;
                          plVar21 = (longlong *)0x0;
                          plStack_d0 = (longlong *)0x0;
                          plStack_c8 = (longlong *)0x0;
                          lVar15 = *(longlong *)
                                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                    0x2e8);
                          uVar25 = puVar23[-1];
                          puVar7 = *(undefined8 **)(lVar15 + 8);
                          *puVar7 = puVar23 + -2;
                          pcVar9 = _Py_FalseStruct_exref;
                          puVar23[-2] = lVar15;
                          puVar23[-1] = (ulonglong)((uint)uVar25 & 3) | (ulonglong)puVar7;
                          *(undefined8 **)(lVar15 + 8) = puVar23 + -2;
                          *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                          puVar23[3] = pcVar9;
                          plVar6 = DAT_23ed6ccf0;
                          lVar15 = *DAT_23ed6ccf0;
                          puVar23[4] = DAT_23ed6ccf0;
                          *plVar6 = lVar15 + 2;
                          puVar23[5] = plVar6;
                          *plVar16 = *plVar16 + 1;
                          puVar23[6] = plVar16;
                          goto LAB_23e714c5e;
                        }
                        plVar19 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eed9e38);
                        if (plVar19 == (longlong *)0x0) {
LAB_23e716401:
                          plVar21 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar25 = *(undefined8 *)(param_1 + 0x60);
                          uVar26 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          plVar21 = (longlong *)FUN_23a38cc10(param_1,plVar19,_DAT_23eeda038);
                          *plVar19 = *plVar19 + -1;
                          if (*plVar19 == 0) {
                            (**(code **)(plVar19[1] + 0x30))(plVar19);
                          }
                          if (plVar21 == (longlong *)0x0) goto LAB_23e716401;
                          plVar19 = (longlong *)FUN_23a388310(plVar21);
                          *plVar21 = *plVar21 + -1;
                          if (*plVar21 == 0) {
                            (**(code **)(plVar21[1] + 0x30))(plVar21);
                          }
                          if (plVar19 == (longlong *)0x0) goto LAB_23e716401;
                          plStack_c8 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
                          if ((plStack_c8 == (longlong *)0x0) &&
                             (plStack_c8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2),
                             plStack_c8 == (longlong *)0x0)) {
                            plStack_d0 = (longlong *)0x0;
                          }
                          else {
                            plStack_d0 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
                            if (((plStack_d0 != (longlong *)0x0) ||
                                (plStack_d0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2),
                                plStack_d0 != (longlong *)0x0)) &&
                               (cVar13 = FUN_23a3884a0(param_1,auStack_98,plVar19,2), cVar13 != '\0'
                               )) {
                              *plVar19 = *plVar19 + -1;
                              if (*plVar19 == 0) {
                                (**(code **)(plVar19[1] + 0x30))(plVar19);
                              }
                              if (*plStack_c8 == 0) {
                                (**(code **)(plStack_c8[1] + 0x30))();
                              }
                              if (*plStack_d0 == 0) {
                                (**(code **)(plStack_d0[1] + 0x30))();
                              }
                              plVar19 = (longlong *)
                                        FUN_23a388650(param_1,plStack_e0,DAT_23ed6ccf0,0);
                              pcVar9 = PyLong_Type_exref;
                              if (plVar19 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0xce;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_b8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar19 = (longlong *)0x0;
                                goto LAB_23e7151e0;
                              }
                              if ((code *)plStack_d0[1] == PyLong_Type_exref) {
                                plVar21 = (longlong *)
                                          (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) +
                                                      0xe8))(plStack_d0,_DAT_23eeda040);
                              }
                              else {
                                plVar21 = (longlong *)FUN_23e8c1be0();
                              }
                              if (plVar21 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar19 = *plVar19 + -1;
                                if (*plVar19 == 0) {
                                  FUN_23a334bc0(plVar19);
                                }
                                uVar24 = 0xce;
                                plVar19 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                goto LAB_23e7151e0;
                              }
                              plStack_b8 = (longlong *)FUN_23e8c09e0(plVar19);
                              *plVar19 = *plVar19 + -1;
                              if (*plVar19 == 0) {
                                (**(code **)(plVar19[1] + 0x30))(plVar19);
                              }
                              *plVar21 = *plVar21 + -1;
                              if (*plVar21 == 0) {
                                (**(code **)(plVar21[1] + 0x30))(plVar21);
                              }
                              if (plStack_b8 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0xce;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plVar19 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7151e0;
                              }
                              plVar21 = (longlong *)FUN_23a388650(param_1,plStack_e0,DAT_23ed6ccf8);
                              if (plVar21 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                plVar19 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar24 = 0xcf;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7151e0;
                              }
                              if ((code *)plStack_c8[1] == pcVar9) {
                                plVar22 = (longlong *)
                                          (**(code **)(*(longlong *)(pcVar9 + 0x60) + 0xe8))
                                                    (plStack_c8,_DAT_23eeda040);
                              }
                              else {
                                plVar22 = (longlong *)FUN_23e8c1be0(plStack_c8);
                              }
                              if (plVar22 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar21 = *plVar21 + -1;
                                if (*plVar21 == 0) {
                                  FUN_23a334bc0(plVar21);
                                }
                                uVar24 = 0xcf;
                                plVar19 = (longlong *)0x0;
                                goto LAB_23e7151e0;
                              }
                              plVar19 = (longlong *)FUN_23e8c09e0(plVar21);
                              *plVar21 = *plVar21 + -1;
                              if (*plVar21 == 0) {
                                (**(code **)(plVar21[1] + 0x30))(plVar21);
                              }
                              *plVar22 = *plVar22 + -1;
                              if (*plVar22 == 0) {
                                (**(code **)(plVar22[1] + 0x30))(plVar22);
                              }
                              if (plVar19 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar24 = 0xcf;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7151e0;
                              }
                              iVar14 = FUN_23a35f020(plVar4);
                              if (iVar14 == -1) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0xd2;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7151e0;
                              }
                              plVar21 = plVar19;
                              if (iVar14 == 0) {
LAB_23e7161d7:
                                lVar15 = *(longlong *)(param_1 + 0x10);
                                puVar23 = *(undefined8 **)(lVar15 + 0xe30);
                                if (puVar23 == (undefined8 *)0x0) {
                                  puVar23 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,4);
                                }
                                else {
                                  uVar25 = puVar23[3];
                                  *(int *)(lVar15 + 0xec4) = *(int *)(lVar15 + 0xec4) + -1;
                                  *(undefined8 *)(lVar15 + 0xe30) = uVar25;
                                  *puVar23 = 1;
                                }
                                lVar15 = *(longlong *)
                                          (*(longlong *)
                                            (*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8
                                          );
                                uVar25 = puVar23[-1];
                                puVar7 = *(undefined8 **)(lVar15 + 8);
                                *puVar7 = puVar23 + -2;
                                pcVar9 = _Py_TrueStruct_exref;
                                puVar23[-2] = lVar15;
                                puVar23[-1] = (ulonglong)((uint)uVar25 & 3) | (ulonglong)puVar7;
                                *(undefined8 **)(lVar15 + 8) = puVar23 + -2;
                                *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                                puVar23[3] = pcVar9;
                                *plStack_b8 = *plStack_b8 + 1;
                                puVar23[4] = plStack_b8;
                                lVar15 = *(longlong *)(param_1 + 0x38);
                                *plVar21 = *plVar21 + 1;
                                lVar5 = *(longlong *)(lVar15 + 8);
                                puVar23[5] = plVar21;
                                *plVar16 = *plVar16 + 1;
                                plVar6 = *(longlong **)(lVar5 + 0x28);
                                uVar25 = *(undefined8 *)(lVar5 + 0x30);
                                puVar23[6] = plVar16;
                                plVar19 = (longlong *)plVar6[2];
                                *(undefined8 *)(lVar15 + 8) = uVar25;
                                *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                                if (plVar19 != (longlong *)0x0) {
                                  plVar6[2] = 0;
                                  *plVar19 = *plVar19 + -1;
                                  if (*plVar19 == 0) {
                                    (**(code **)(plVar19[1] + 0x30))();
                                  }
                                }
                                *plVar6 = *plVar6 + -1;
                                if (*plVar6 == 0) {
                                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                                }
                                plVar6[0xf] = 0;
LAB_23e714c5e:
                                *plVar20 = *plVar20 + -1;
                                if (*plVar20 == 0) {
                                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                                }
                                *plVar18 = *plVar18 + -1;
                                if (*plVar18 == 0) {
                                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                                }
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                                }
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                }
                                lVar15 = *plStack_e8;
                                *plStack_e8 = lVar15 + -1;
                                if (lVar15 + -1 == 0) {
                                  (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
                                }
                                lVar15 = *plStack_e0;
                                *plStack_e0 = lVar15 + -1;
                                if (lVar15 + -1 == 0) {
                                  (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                                }
                                if ((plStack_c8 != (longlong *)0x0) &&
                                   (lVar15 = *plStack_c8, *plStack_c8 = lVar15 + -1,
                                   lVar15 + -1 == 0)) {
                                  (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                                }
                                if ((plStack_d0 != (longlong *)0x0) &&
                                   (lVar15 = *plStack_d0, *plStack_d0 = lVar15 + -1,
                                   lVar15 + -1 == 0)) {
                                  (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                                }
                                if ((plStack_b8 != (longlong *)0x0) &&
                                   (lVar15 = *plStack_b8, *plStack_b8 = lVar15 + -1,
                                   lVar15 + -1 == 0)) {
                                  (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                                }
                                if ((plVar21 != (longlong *)0x0) &&
                                   (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                                  (**(code **)(plVar21[1] + 0x30))(plVar21);
                                }
                                lVar15 = *plVar1;
                                *plVar1 = lVar15 + -1;
                                if (lVar15 + -1 == 0) {
                                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                                }
                                *plVar2 = *plVar2 + -1;
                                if (*plVar2 == 0) {
                                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                                }
                                lVar15 = *plVar3;
                                *plVar3 = lVar15 + -1;
                                if (lVar15 + -1 == 0) {
                                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                                }
                                lVar15 = *plVar4;
                                *plVar4 = lVar15 + -1;
                                if (lVar15 + -1 != 0) {
                                  return puVar23;
                                }
                                (**(code **)(plVar4[1] + 0x30))(plVar4);
                                return puVar23;
                              }
                              plStack_78 = plStack_b8;
                              plVar21 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9ef0);
                              if (plVar21 != (longlong *)0x0) {
                                cVar13 = FUN_23e8bf180(&plStack_78,plVar21);
                                *plVar21 = *plVar21 + -1;
                                if (*plVar21 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (cVar13 != '\0') {
                                  plStack_b8 = plStack_78;
                                  plStack_78 = plVar19;
                                  plVar21 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9f80);
                                  if (plVar21 != (longlong *)0x0) {
                                    cVar13 = FUN_23e8bf180(&plStack_78,plVar21);
                                    *plVar21 = *plVar21 + -1;
                                    if (*plVar21 == 0) {
                                      FUN_23a334bc0(plVar21);
                                    }
                                    plVar21 = plStack_78;
                                    if (cVar13 != '\0') goto LAB_23e7161d7;
                                  }
                                  auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                  uVar24 = 0xd4;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e7151e0;
                                }
                              }
                              auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              uVar24 = 0xd3;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23e7151e0;
                            }
                          }
                          plVar21 = plStack_88;
                          uVar25 = auStack_98._0_8_;
                          uVar26 = auStack_98._8_8_;
                          plStack_88 = (longlong *)0x0;
                          auStack_98 = (undefined1  [16])0x0;
                          *plVar19 = *plVar19 + -1;
                          if (*plVar19 == 0) {
                            (**(code **)(plVar19[1] + 0x30))(plVar19);
                          }
                          plStack_88 = (longlong *)0x0;
                          auStack_98 = (undefined1  [16])0x0;
                          if ((plStack_c8 != (longlong *)0x0) &&
                             (lVar15 = *plStack_c8, *plStack_c8 = lVar15 + -1, lVar15 + -1 == 0)) {
                            (**(code **)(plStack_c8[1] + 0x30))();
                          }
                          if ((plStack_d0 != (longlong *)0x0) &&
                             (lVar15 = *plStack_d0, *plStack_d0 = lVar15 + -1, lVar15 + -1 == 0)) {
                            (**(code **)(plStack_d0[1] + 0x30))();
                          }
                        }
                        plVar19 = (longlong *)0x0;
                        uVar24 = 0xcd;
                        plStack_b8 = (longlong *)0x0;
                        plStack_d0 = (longlong *)0x0;
                        plStack_c8 = (longlong *)0x0;
                        auStack_98._8_8_ = uVar26;
                        auStack_98._0_8_ = uVar25;
                        plStack_88 = plVar21;
                        goto LAB_23e7151e0;
                      }
                      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_88 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      iVar14 = *(int *)(lVar15 + 0xc);
                      if (*(int *)(lVar15 + 0xc) == 0) {
                        *(int *)(lVar15 + 0xc) = DAT_23ec15484;
                        iVar14 = DAT_23ec15484;
                        DAT_23ec15484 = DAT_23ec15484 + 1;
                      }
                      if (_DAT_23ec15468 != iVar14) {
                        _DAT_23ec15468 = iVar14;
                        _DAT_23eedb080 =
                             FUN_23e8cbd60(lVar15,_DAT_23eeda030,
                                           *(undefined8 *)(_DAT_23eeda030 + 0x18));
                      }
                      if (-1 < _DAT_23eedb080) {
                        lVar5 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                        if (*(longlong *)(lVar5 + 8 + _DAT_23eedb080 * 0x10) != 0)
                        goto LAB_23e714b27;
                        _DAT_23eedb080 =
                             FUN_23e8cbd60(lVar15,_DAT_23eeda030,
                                           *(undefined8 *)(_DAT_23eeda030 + 0x18));
                        if (-1 < _DAT_23eedb080) {
                          lVar15 = *(longlong *)(lVar5 + 8 + _DAT_23eedb080 * 0x10);
                          goto LAB_23e715d71;
                        }
                      }
LAB_23e715d80:
                      plVar19 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeda030);
                      if ((plVar19 != (longlong *)0x0) && (*plVar19 != 0)) goto LAB_23e714b27;
                      FUN_23e915740(param_1,auStack_98,_DAT_23eeda030);
                    }
                    plStack_b8 = (longlong *)0x0;
                    uVar24 = 0xcb;
                    plVar19 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    goto LAB_23e7151e0;
                  }
                }
              }
            }
            plVar21 = plStack_88;
            uVar25 = auStack_98._0_8_;
            uVar26 = auStack_98._8_8_;
            plStack_88 = (longlong *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            plStack_88 = (longlong *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if ((plStack_e8 != (longlong *)0x0) &&
               (lVar15 = *plStack_e8, *plStack_e8 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
            }
            if ((plStack_e0 != (longlong *)0x0) &&
               (lVar15 = *plStack_e0, *plStack_e0 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
            }
            goto LAB_23e71582f;
          }
        }
        uVar25 = *(undefined8 *)(param_1 + 0x60);
        plVar21 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = *(undefined8 *)(param_1 + 0x68);
      }
LAB_23e71582f:
      plVar19 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar17 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      uVar24 = 0xc9;
      plStack_d0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      auStack_98._8_8_ = uVar26;
      auStack_98._0_8_ = uVar25;
      plStack_88 = plVar21;
      goto LAB_23e7151e0;
    }
    plVar18 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9f80);
    if (plVar18 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      plVar19 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar17 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar24 = 0xc1;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar18 = (longlong *)0x0;
      goto LAB_23e7151e0;
    }
    plVar20 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9f80);
    if (plVar20 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar18 = *plVar18 + -1;
      plVar20 = (longlong *)0x0;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
LAB_23e7150e2:
      plStack_b8 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar17 = (longlong *)0x0;
      uVar24 = 0xc1;
      plStack_c8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      goto LAB_23e7151e0;
    }
    plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9fa0);
    if (plVar16 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
      plStack_b8 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar17 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar24 = 0xc1;
      plStack_c8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      goto LAB_23e7151e0;
    }
    plVar17 = (longlong *)FUN_23e8c09e0(plVar20,plVar16);
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    pcVar9 = _Py_NoneStruct_exref;
    if (plVar17 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      plStack_b8 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar24 = 0xc1;
      plStack_c8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plVar17 = (longlong *)0x0;
      goto LAB_23e7151e0;
    }
    lVar15 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar18,plVar17,_Py_NoneStruct_exref);
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    lVar5 = *(longlong *)(param_1 + 0x10);
    plVar18 = *(longlong **)(lVar5 + 0xe20);
    if (plVar18 == (longlong *)0x0) {
      plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar8 = plVar18[3];
      *(int *)(lVar5 + 0xebc) = *(int *)(lVar5 + 0xebc) + -1;
      *(longlong *)(lVar5 + 0xe20) = lVar8;
      *plVar18 = 1;
    }
    pcVar10 = _PyRuntime_exref;
    plVar18[4] = 0;
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar10 + 0x1f8) + 0x10) + 0x2e8);
    lVar8 = plVar18[-1];
    puVar23 = *(undefined8 **)(lVar5 + 8);
    *puVar23 = plVar18 + -2;
    uVar25 = DAT_23eed9ef0;
    plVar18[-2] = lVar5;
    plVar18[-1] = (ulonglong)((uint)lVar8 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar5 + 8) = plVar18 + -2;
    plVar18[3] = lVar15;
    plVar20 = (longlong *)FUN_23a38cc10(param_1,plVar4,uVar25);
    if (plVar20 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9ef0);
      if (plVar16 != (longlong *)0x0) {
        plVar17 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed9f90);
        if (plVar17 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20,0);
          }
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          goto LAB_23e715cb9;
        }
        plVar19 = (longlong *)FUN_23e8c09e0(plVar16);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if (plVar19 != (longlong *)0x0) {
          lVar15 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar20,plVar19,pcVar9);
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          plVar18[4] = lVar15;
          plVar20 = (longlong *)FUN_23a38cc10(param_1,plVar2,plVar18);
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if (plVar20 != (longlong *)0x0) goto LAB_23e7148a9;
          plStack_88 = *(longlong **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7150e2;
        }
      }
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
    }
LAB_23e715cb9:
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    uVar24 = 0xc2;
  }
  plStack_b8 = (longlong *)0x0;
  plVar16 = (longlong *)0x0;
  plVar18 = (longlong *)0x0;
  plVar19 = (longlong *)0x0;
  plStack_d0 = (longlong *)0x0;
  plVar17 = (longlong *)0x0;
  plVar20 = (longlong *)0x0;
  plStack_c8 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
LAB_23e7151e0:
  plVar22 = plStack_88;
  plVar21 = DAT_23ed6a4f8;
  if (plStack_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar21 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar22 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar22;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar21[2] = 0;
    plVar21[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar15 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar21 + 0x24) = uVar24;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar21 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar5 = plVar21[-1];
    puVar23 = *(undefined8 **)(lVar15 + 8);
    *puVar23 = plVar21 + -2;
    plVar21[-2] = lVar15;
    plVar21[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar15 + 8) = plVar21 + -2;
    plVar22 = plVar21;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  else if ((longlong *)plStack_88[3] != plVar6) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar21 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar21[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar15 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar21 + 0x24) = uVar24;
    *(undefined4 *)(plVar21 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
    lVar5 = plVar21[-1];
    puVar23 = *(undefined8 **)(lVar15 + 8);
    *puVar23 = plVar21 + -2;
    plVar21[-2] = lVar15;
    plVar21[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar15 + 8) = plVar21 + -2;
    plVar21[2] = (longlong)plVar22;
    *plVar22 = *plVar22 + 1;
    plVar22 = plVar21;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  plStack_88 = plVar22;
  FUN_23e8bba40(plVar6,"oooooooooooooo",plVar1,plVar2,plVar3,plVar4,plVar20,plVar18,plVar17,plVar16,
                plStack_e8,plStack_e0,plStack_c8,plStack_d0,plStack_b8,plVar19);
  if (_DAT_23eedb090 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eedb090 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar15 + 0x28);
  plVar21 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar21 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar21 = *plVar21 + -1;
    if (*plVar21 == 0) {
      (**(code **)(plVar21[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar21 = plStack_88;
  auVar11 = auStack_98;
  plVar6[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  plStack_88 = (longlong *)0x0;
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar15 = *plStack_e8, *plStack_e8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar15 = *plStack_e0, *plStack_e0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar15 = *plStack_c8, *plStack_c8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plStack_d0 != (longlong *)0x0) &&
     (lVar15 = *plStack_d0, *plStack_d0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar15 = *plStack_b8, *plStack_b8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  lVar15 = *plVar1;
  *plVar1 = lVar15 + -1;
  auStack_98 = auVar11;
  plStack_88 = plVar21;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar15 = *plVar3;
  *plVar3 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar15 = *plVar4;
  *plVar4 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,plStack_88);
  return (undefined8 *)0x0;
}
