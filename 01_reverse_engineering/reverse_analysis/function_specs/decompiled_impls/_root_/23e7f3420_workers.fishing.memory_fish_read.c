/* ===== 23e7f3420 workers.fishing.memory_fish_read:? ===== */
/* ghidra_name=FUN_23e7f3420 entry=23e7f3420 size=8472 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7f3420(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  bool bVar9;
  int iVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  undefined8 uVar16;
  code *pcVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong lVar21;
  code *pcVar22;
  code *pcVar23;
  code *pcVar24;
  code *pcVar25;
  undefined4 uVar26;
  code *pcVar27;
  undefined1 auVar28 [8];
  code *pcStack_f0;
  undefined1 auStack_b8 [16];
  code *apcStack_a8 [2];
  undefined1 auStack_98 [8];
  code *pcStack_90;
  code *apcStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar12 = _DAT_23eedea90;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  if (_DAT_23eedea90 == (longlong *)0x0) {
LAB_23e7f3481:
    _DAT_23eedea90 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedea88,DAT_23eedebc0,0x28);
  }
  else {
    lVar11 = *_DAT_23eedea90;
    if (1 < lVar11) {
      *_DAT_23eedea90 = lVar11 + -1;
      goto LAB_23e7f3481;
    }
    if (_DAT_23eedea90[2] != 0) {
      *_DAT_23eedea90 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e7f3481;
    }
  }
  plVar8 = _DAT_23eedea90;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eedea90 + 9;
  lVar21 = *(longlong *)(lVar11 + 8);
  _DAT_23eedea90[0xf] = lVar21;
  *(longlong **)(lVar11 + 8) = plVar12;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  *(undefined4 *)(plVar8 + 8) = 0;
  lVar11 = FUN_23e8dd3d0();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeddf18);
    if (apcStack_88[0] != (code *)0x0) {
      plVar13 = (longlong *)0x0;
      if (*(longlong **)(apcStack_88[0] + 0x18) == plVar8) goto LAB_23e7f4872;
LAB_23e7f48b8:
      pcStack_f0 = (code *)0x0;
      pcVar25 = (code *)0x0;
      uVar26 = 0xe1;
LAB_23e7f4570:
      pcVar15 = apcStack_88[0];
      pcVar17 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar22 = _PyRuntime_exref;
      *(longlong **)(pcVar17 + 0x18) = plVar8;
      *plVar8 = *plVar8 + 1;
      lVar11 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x24) = uVar26;
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar21 = *(longlong *)(pcVar17 + -8);
      puVar3 = *(undefined8 **)(lVar11 + 8);
      *puVar3 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar11;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
      *(code **)(lVar11 + 8) = pcVar17 + -0x10;
      *(code **)(pcVar17 + 0x10) = pcVar15;
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
      }
      goto LAB_23e7f4624;
    }
LAB_23e7f4d30:
    pcStack_f0 = (code *)0x0;
    pcVar25 = (code *)0x0;
    plVar13 = (longlong *)0x0;
    uVar26 = 0xe1;
  }
  else {
    *(undefined4 *)(plVar8 + 5) = 0xe1;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
    if (plVar12 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      apcStack_88[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_88[0] != (code *)0x0) {
        if (*(longlong **)(apcStack_88[0] + 0x18) == plVar8) goto LAB_23e7f4872;
        pcStack_f0 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        uVar26 = 0xe1;
        pcVar25 = (code *)0x0;
        goto LAB_23e7f4570;
      }
      goto LAB_23e7f4d30;
    }
    plVar13 = (longlong *)FUN_23e8c09e0(plVar12,plVar2);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      apcStack_88[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_88[0] != (code *)0x0) {
        if (plVar8 != *(longlong **)(apcStack_88[0] + 0x18)) goto LAB_23e7f48b8;
LAB_23e7f4872:
        pcStack_f0 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        pcVar25 = (code *)0x0;
        pcVar17 = apcStack_88[0];
        goto LAB_23e7f4624;
      }
      goto LAB_23e7f4d30;
    }
    pcStack_f0 = (code *)0x0;
    pcVar25 = (code *)0x0;
    do {
      lVar11 = FUN_23e8dd3d0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eeddf18);
        if (apcStack_88[0] == (code *)0x0) {
LAB_23e7f4dd8:
          uVar26 = 0xe2;
          goto LAB_23e7f4b70;
        }
        plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
joined_r0x00023e7f455f:
        pcVar17 = apcStack_88[0];
        if (plVar12 == plVar8) goto LAB_23e7f4624;
        uVar26 = 0xe2;
        goto LAB_23e7f4570;
      }
      *(undefined4 *)(plVar8 + 5) = 0xe2;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
      if (plVar12 == (longlong *)0x0) {
LAB_23e7f48c8:
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (apcStack_88[0] != (code *)0x0) {
          plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
          goto joined_r0x00023e7f455f;
        }
        goto LAB_23e7f4dd8;
      }
      plVar14 = (longlong *)FUN_23e8d09c0(plVar12,plVar13);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e7f48c8;
      iVar10 = FUN_23a35f020(plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (iVar10 == -1) goto LAB_23e7f48c8;
      if (iVar10 == 0) {
        lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar12 = *(longlong **)(lVar11 + 0x28);
        plVar8 = (longlong *)plVar12[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
        *(undefined4 *)(plVar12 + 8) = 0xffffffff;
        if (plVar8 != (longlong *)0x0) {
          plVar12[2] = 0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))();
          }
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        pcVar17 = _Py_NoneStruct_exref;
        plVar12[0xf] = 0;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        pcVar15 = pcVar25;
        if (pcVar25 == (code *)0x0) goto LAB_23e7f4f4a;
LAB_23e7f4f2e:
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
        if (*(longlong *)pcVar15 == 0) {
          (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
        }
LAB_23e7f4f4a:
        if ((pcStack_f0 != (code *)0x0) &&
           (*(longlong *)pcStack_f0 = *(longlong *)pcStack_f0 + -1, *(longlong *)pcStack_f0 == 0)) {
          (**(code **)(*(longlong *)(pcStack_f0 + 8) + 0x30))(pcStack_f0);
        }
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar17;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar17;
      }
      lVar11 = FUN_23e8dd3d0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eeddf18);
        if (apcStack_88[0] == (code *)0x0) {
LAB_23e7f4e98:
          uVar26 = 0xe3;
          goto LAB_23e7f4b70;
        }
        pcVar17 = apcStack_88[0];
        if (*(longlong **)(apcStack_88[0] + 0x18) == plVar8) goto LAB_23e7f4624;
LAB_23e7f4835:
        uVar26 = 0xe3;
        goto LAB_23e7f4570;
      }
      *(undefined4 *)(plVar8 + 5) = 0xe3;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
      if (plVar12 == (longlong *)0x0) {
LAB_23e7f4ce0:
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (apcStack_88[0] == (code *)0x0) goto LAB_23e7f4e98;
        pcVar17 = apcStack_88[0];
        if (plVar8 != *(longlong **)(apcStack_88[0] + 0x18)) goto LAB_23e7f4835;
        goto LAB_23e7f4624;
      }
      pcVar15 = (code *)FUN_23e8c6640(plVar13,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (pcVar15 == (code *)0x0) goto LAB_23e7f4ce0;
      if ((pcVar25 != (code *)0x0) &&
         (*(longlong *)pcVar25 = *(longlong *)pcVar25 + -1, *(longlong *)pcVar25 == 0)) {
        (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
      }
      pcVar25 = pcVar15;
      if (plVar1 == (longlong *)0x0) {
        pcStack_90 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eeddf28);
        auStack_98 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_98 = *(longlong *)auStack_98 + 1;
        apcStack_88[0] = (code *)0x0;
        if (auStack_98 != (undefined1  [8])_Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
joined_r0x00023e7f50e9:
        if (apcStack_88[0] == (code *)0x0) {
LAB_23e7f4b64:
          uVar26 = 0xe4;
          goto LAB_23e7f4b70;
        }
        uVar26 = 0xe4;
        plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
        goto joined_r0x00023e7f507b;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde80);
      if (plVar12 == (longlong *)0x0) {
LAB_23e7f4980:
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto joined_r0x00023e7f50e9;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeddf00);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e7f4980;
      uVar16 = FUN_23a3a0d40(DAT_23eeddd00);
      pcStack_78 = _DAT_23eeddf30;
      *(undefined4 *)(plVar8 + 5) = 0xe4;
      pcStack_70 = pcVar15;
      pcVar17 = (code *)FUN_23e94ed00(param_1,uVar16,&pcStack_78);
      if (pcVar17 == (code *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
          goto joined_r0x00023e7f50e9;
        }
        if (apcStack_88[0] == (code *)0x0) goto LAB_23e7f4b64;
        uVar26 = 0xe4;
        plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
        goto joined_r0x00023e7f507b;
      }
      *(undefined4 *)(plVar8 + 5) = 0xe4;
      pcStack_78 = pcVar17;
      plVar12 = (longlong *)FUN_23e9186b0(param_1,plVar14,&pcStack_78,_DAT_23eeddeb8);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
      if (*(longlong *)pcVar17 == 0) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e7f4980;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde58);
      if (plVar12 == (longlong *)0x0) {
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7f5058:
        apcStack_88[0] = pcVar17;
        auStack_98 = auVar28;
        pcStack_90 = pcVar22;
        if (pcVar17 != (code *)0x0) {
          uVar26 = 0xe5;
          plVar12 = *(longlong **)(pcVar17 + 0x18);
          goto joined_r0x00023e7f507b;
        }
LAB_23e7f53b5:
        uVar26 = 0xe5;
        goto LAB_23e7f4b70;
      }
      plVar14 = (longlong *)FUN_23e8d9880(plVar12,DAT_23ed6cd90);
      if (plVar14 == (longlong *)0x0) {
LAB_23e7f4d48:
        auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        apcStack_88[0] = (code *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        pcStack_90 = (code *)0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 != 0) goto LAB_23e7f5058;
        (**(code **)(plVar12[1] + 0x30))(plVar12);
LAB_23e7f4da5:
        apcStack_88[0] = pcVar17;
        auStack_98 = auVar28;
        pcStack_90 = pcVar22;
        if (pcVar17 == (code *)0x0) goto LAB_23e7f53b5;
        uVar26 = 0xe5;
        plVar12 = *(longlong **)(pcVar17 + 0x18);
        goto joined_r0x00023e7f507b;
      }
      *(undefined4 *)(plVar8 + 5) = 0xe5;
      plVar18 = (longlong *)FUN_23e91a870(param_1,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar18 == (longlong *)0x0) goto LAB_23e7f4d48;
      plVar14 = (longlong *)FUN_23e8d9880(plVar12,DAT_23ed6cd98);
      if (plVar14 == (longlong *)0x0) {
        auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        apcStack_88[0] = (code *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        pcStack_90 = (code *)0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 != 0) {
          lVar11 = *plVar18;
          *plVar18 = lVar11 + -1;
          if (lVar11 + -1 == 0) {
            iVar10 = 0xe5;
            (**(code **)(plVar18[1] + 0x30))();
            goto LAB_23e7f3e74;
          }
          goto LAB_23e7f4da5;
        }
        iVar10 = 0xe5;
LAB_23e7f4ca7:
        pcStack_90 = (code *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        apcStack_88[0] = (code *)0x0;
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        lVar11 = *plVar18;
        *plVar18 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
LAB_23e7f3e2f:
          (**(code **)(plVar18[1] + 0x30))();
        }
        if (plVar14 != (longlong *)0x0) goto LAB_23e7f3e4d;
LAB_23e7f3e74:
        auStack_98 = auVar28;
        pcStack_90 = pcVar22;
        if (pcVar17 == (code *)0x0) {
          apcStack_88[0] = (code *)0x0;
          if (iVar10 != 0) goto LAB_23e7f53b5;
          uVar26 = (undefined4)plVar8[5];
          goto LAB_23e7f4b70;
        }
        if (*(longlong **)(pcVar17 + 0x18) == plVar8) goto LAB_23e7f4624;
        apcStack_88[0] = pcVar17;
        if (iVar10 == 0) {
          uVar26 = (undefined4)plVar8[5];
        }
        else {
          uVar26 = 0xe5;
        }
        goto LAB_23e7f4570;
      }
      plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde60);
      if (plVar19 == (longlong *)0x0) {
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7f3f69:
        uVar26 = 0xe6;
LAB_23e7f39f0:
        pcVar17 = apcStack_88[0];
        auStack_b8._8_8_ = pcStack_90;
        auStack_b8._0_8_ = auStack_98;
        apcStack_88[0] = (code *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        pcStack_90 = (code *)0x0;
        apcStack_a8[0] = pcVar17;
        plVar19 = *(longlong **)(param_1 + 0x138);
        if (plVar19 != (longlong *)0x0) {
          *plVar19 = *plVar19 + 1;
        }
        pcVar22 = DAT_23ed6a4f8;
        if (pcVar17 == (code *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar17 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar17;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          pcVar17 = _PyRuntime_exref;
          *(longlong *)(pcVar22 + 0x10) = 0;
          *(longlong **)(pcVar22 + 0x18) = plVar8;
          *plVar8 = *plVar8 + 1;
          lVar11 = *(longlong *)(pcVar17 + 0x1f8);
          *(undefined4 *)(pcVar22 + 0x24) = uVar26;
          lVar11 = *(longlong *)(lVar11 + 0x10);
          *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
          lVar11 = *(longlong *)(lVar11 + 0x2e8);
          lVar21 = *(longlong *)(pcVar22 + -8);
          puVar3 = *(undefined8 **)(lVar11 + 8);
          *puVar3 = pcVar22 + -0x10;
          *(longlong *)(pcVar22 + -0x10) = lVar11;
          *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
          *(code **)(lVar11 + 8) = pcVar22 + -0x10;
          if ((apcStack_a8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
             *(longlong *)apcStack_a8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))(apcStack_a8[0]);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar4 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar4;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          pcVar4 = _PyRuntime_exref;
          *(longlong **)(pcVar22 + 0x18) = plVar8;
          *plVar8 = *plVar8 + 1;
          lVar11 = *(longlong *)(pcVar4 + 0x1f8);
          *(undefined4 *)(pcVar22 + 0x24) = uVar26;
          *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
          lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
          lVar21 = *(longlong *)(pcVar22 + -8);
          puVar3 = *(undefined8 **)(lVar11 + 8);
          *puVar3 = pcVar22 + -0x10;
          *(longlong *)(pcVar22 + -0x10) = lVar11;
          *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
          *(code **)(lVar11 + 8) = pcVar22 + -0x10;
          *(code **)(pcVar22 + 0x10) = pcVar17;
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
          if ((apcStack_a8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
             *(longlong *)apcStack_a8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
          }
        }
        pcVar17 = _Py_NoneStruct_exref;
        apcStack_a8[0] = pcVar22;
        if (((code *)auStack_b8._0_8_ != _Py_NoneStruct_exref) &&
           ((code *)auStack_b8._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
        }
        plVar20 = *(longlong **)(auStack_b8._8_8_ + 0x28);
        if (apcStack_a8[0] == pcVar17) {
          pcVar22 = (code *)0x0;
        }
        else {
          pcVar22 = apcStack_a8[0];
          if (apcStack_a8[0] != (code *)0x0) {
            *(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + 1;
          }
        }
        *(code **)(auStack_b8._8_8_ + 0x28) = pcVar22;
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
        if ((apcStack_a8[0] != (code *)0x0) &&
           (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
           *(longlong *)apcStack_a8[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
        }
        pcVar22 = *(code **)(param_1 + 0x138);
        apcStack_a8[0] = (code *)0x0;
        auStack_b8 = (undefined1  [16])0x0;
        pcVar4 = *(code **)PyExc_BaseException_exref;
        pcVar27 = *(code **)(pcVar22 + 8);
        if ((*(uint *)(*(longlong *)(pcVar4 + 8) + 0xa8) & 0x4000000) != 0) {
          lVar11 = *(longlong *)(pcVar4 + 0x10);
          if (0 < lVar11) {
            lVar21 = 0;
            do {
              if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar4 + lVar21 * 8 + 0x18) + 8) + 0xa8
                                )) ||
                 ((*(byte *)(*(longlong *)(pcVar4 + lVar21 * 8 + 0x18) + 0xab) & 0x40) == 0))
              goto LAB_23e7f3f78;
              lVar21 = lVar21 + 1;
            } while (lVar11 != lVar21);
            lVar21 = 0;
            while (iVar10 = FUN_23a35ebd0(param_1,pcVar27,
                                          *(undefined8 *)(pcVar4 + lVar21 * 8 + 0x18)), iVar10 == 0)
            {
              lVar21 = lVar21 + 1;
              if (lVar11 == lVar21) {
                pcVar22 = *(code **)(param_1 + 0x138);
                goto LAB_23e7f3cd3;
              }
            }
LAB_23e7f3fe9:
            pcVar22 = *(code **)(param_1 + 0x138);
            goto LAB_23e7f3ff0;
          }
          goto LAB_23e7f3cd3;
        }
        if (((int)*(uint *)(*(longlong *)(pcVar4 + 8) + 0xa8) < 0) &&
           (((byte)pcVar4[0xab] & 0x40) != 0)) {
          pcVar24 = *(code **)(pcVar27 + 8);
          if ((*(uint *)(pcVar24 + 0xa8) & 0x40000000) == 0) {
            pcVar23 = pcVar27;
            if ((-1 < (int)*(uint *)(pcVar24 + 0xa8)) ||
               (pcVar24 = pcVar27, ((byte)pcVar27[0xab] & 0x40) == 0)) goto LAB_23e7f4a06;
          }
          else {
            pcVar23 = pcVar24;
            if (-1 < *(int *)(*(longlong *)(pcVar24 + 8) + 0xa8)) {
LAB_23e7f4a06:
              if (pcVar4 != pcVar23) goto LAB_23e7f3cd3;
              goto LAB_23e7f3ff4;
            }
          }
          lVar11 = *(longlong *)(pcVar24 + 0x158);
          if (lVar11 == 0) {
            do {
              if (pcVar4 == pcVar24) goto LAB_23e7f3ff0;
              pcVar24 = *(code **)(pcVar24 + 0x100);
            } while (pcVar24 != (code *)0x0);
            if (pcVar4 == PyBaseObject_Type_exref) goto LAB_23e7f3ff0;
          }
          else if (0 < *(longlong *)(lVar11 + 0x10)) {
            lVar21 = 0;
            while (pcVar4 != *(code **)(lVar11 + 0x18 + lVar21 * 8)) {
              lVar21 = lVar21 + 1;
              if (*(longlong *)(lVar11 + 0x10) == lVar21) goto LAB_23e7f3cd3;
            }
LAB_23e7f3ff0:
            pcVar27 = *(code **)(pcVar22 + 8);
            goto LAB_23e7f3ff4;
          }
LAB_23e7f3cd3:
          pcStack_90 = pcVar22;
          if ((pcVar22 == pcVar17) || (pcVar22 == (code *)0x0)) {
            auVar28 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
            pcVar22 = (code *)PyUnicode_FromString("No active exception to reraise");
            pcVar17 = (code *)0x0;
            pcVar15 = *(code **)(param_1 + 0x138);
            bVar9 = true;
            *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
            goto LAB_23e7f4ff1;
          }
          auVar28 = *(undefined1 (*) [8])(pcVar22 + 8);
          pcVar17 = *(code **)(pcVar22 + 0x28);
          *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
          *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
          if (pcVar17 == (code *)0x0) {
            iVar10 = 0;
            bVar9 = true;
            *(longlong **)(param_1 + 0x138) = plVar19;
            pcVar15 = pcVar22;
          }
          else {
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
            if (*(longlong **)(pcVar17 + 0x18) == plVar8) {
              *(undefined4 *)(plVar8 + 5) = *(undefined4 *)(pcVar17 + 0x24);
            }
            bVar9 = true;
LAB_23e7f3d24:
            iVar10 = 0;
            *(longlong **)(param_1 + 0x138) = plVar19;
            pcVar15 = pcVar22;
          }
LAB_23e7f3d4b:
          apcStack_88[0] = (code *)0x0;
          _auStack_98 = (undefined1  [16])0x0;
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) {
            (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
          }
        }
        else {
LAB_23e7f3f78:
          plVar20 = *(longlong **)PyExc_TypeError_exref;
          uVar16 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar5 = *(longlong **)(param_1 + 0x60);
          plVar6 = *(longlong **)(param_1 + 0x68);
          plVar7 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar20;
          *plVar20 = *plVar20 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar16;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
            (**(code **)(plVar5[1] + 0x30))();
          }
          if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if ((plVar7 == (longlong *)0x0) || (*plVar7 = *plVar7 + -1, *plVar7 != 0))
          goto LAB_23e7f3fe9;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
          pcVar22 = *(code **)(param_1 + 0x138);
          pcVar27 = *(code **)(pcVar22 + 8);
LAB_23e7f3ff4:
          pcStack_68 = *(code **)(pcVar22 + 0x28);
          *(undefined4 *)(plVar8 + 5) = 0xe5;
          if (pcStack_68 == (code *)0x0) {
            pcStack_68 = pcVar17;
          }
          pcStack_78 = pcVar27;
          pcStack_70 = pcVar22;
          plVar20 = (longlong *)FUN_23e956150(param_1,plVar14,&pcStack_78);
          if (plVar20 != (longlong *)0x0) {
            iVar10 = FUN_23a35f020(plVar20);
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              (**(code **)(plVar20[1] + 0x30))();
            }
            if (iVar10 != -1) {
              if (iVar10 != 0) {
                plVar20 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar19;
                if (plVar20 != (longlong *)0x0) goto LAB_23e7f4087;
                goto LAB_23e7f4094;
              }
              bVar9 = false;
              pcVar22 = *(code **)(param_1 + 0x138);
              pcStack_90 = pcVar22;
              if ((pcVar22 == pcVar17) || (pcVar22 == (code *)0x0)) {
                auVar28 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                pcVar22 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar17 = (code *)0x0;
                pcVar15 = *(code **)(param_1 + 0x138);
                *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
                bVar9 = false;
                goto LAB_23e7f4ff1;
              }
              auVar28 = *(undefined1 (*) [8])(pcVar22 + 8);
              pcVar17 = *(code **)(pcVar22 + 0x28);
              *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
              *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
              if (pcVar17 != (code *)0x0) {
                *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                if (*(longlong **)(pcVar17 + 0x18) == plVar8) {
                  *(undefined4 *)(plVar8 + 5) = *(undefined4 *)(pcVar17 + 0x24);
                }
                goto LAB_23e7f3d24;
              }
              iVar10 = 0;
              *(longlong **)(param_1 + 0x138) = plVar19;
              pcVar15 = pcVar22;
              goto LAB_23e7f3d4b;
            }
          }
          pcVar17 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          bVar9 = false;
          pcVar15 = *(code **)(param_1 + 0x138);
          auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar22 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7f4ff1:
          iVar10 = 0xe5;
          *(longlong **)(param_1 + 0x138) = plVar19;
          if (pcVar15 != (code *)0x0) goto LAB_23e7f3d4b;
        }
        apcStack_88[0] = (code *)0x0;
        _auStack_98 = (undefined1  [16])0x0;
        pcStack_78 = (code *)auVar28;
        pcStack_70 = pcVar22;
        pcStack_68 = pcVar17;
        if (bVar9) {
          *(undefined4 *)(plVar8 + 5) = 0xe5;
          plVar19 = (longlong *)FUN_23e957a30(param_1,plVar14,DAT_23eedde28);
          if (plVar19 == (longlong *)0x0) {
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            iVar10 = 0xe5;
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            FUN_23a35d6b0(&pcStack_78);
            pcVar17 = apcStack_88[0];
            auVar28 = auStack_98;
            pcVar22 = pcStack_90;
          }
          else {
            *plVar19 = *plVar19 + -1;
            pcVar17 = pcStack_68;
            auVar28 = (undefined1  [8])pcStack_78;
            pcVar22 = pcStack_70;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
              pcVar17 = pcStack_68;
              auVar28 = (undefined1  [8])pcStack_78;
              pcVar22 = pcStack_70;
            }
          }
        }
LAB_23e7f3df7:
        apcStack_88[0] = (code *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        pcStack_90 = (code *)0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) goto LAB_23e7f4ca7;
        lVar11 = *plVar18;
        *plVar18 = lVar11 + -1;
        if (lVar11 + -1 == 0) goto LAB_23e7f3e2f;
LAB_23e7f3e4d:
        lVar11 = *plVar14;
        *plVar14 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        goto LAB_23e7f3e74;
      }
      iVar10 = FUN_23a35f020(plVar19);
      lVar11 = *plVar19 + -1;
      if (iVar10 == -1) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar19 = lVar11;
        if (lVar11 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        goto LAB_23e7f3f69;
      }
      *plVar19 = lVar11;
      if (lVar11 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      if (iVar10 != 0) {
        plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde60);
        if (plVar19 == (longlong *)0x0) {
LAB_23e7f4438:
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          uVar26 = 0xe7;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7f39f0;
        }
        plVar20 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeddf38);
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        uVar16 = _DAT_23eeddc40;
        if (plVar20 == (longlong *)0x0) goto LAB_23e7f4438;
        *(undefined4 *)(plVar8 + 5) = 0xe7;
        pcVar17 = (code *)FUN_23e94bb80(param_1,plVar20,uVar16);
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
        }
        if (pcVar17 == (code *)0x0) goto LAB_23e7f4438;
        if ((pcStack_f0 != (code *)0x0) &&
           (lVar11 = *(longlong *)pcStack_f0, *(longlong *)pcStack_f0 = lVar11 + -1,
           lVar11 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_f0 + 8) + 0x30))();
        }
        plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde60);
        pcStack_f0 = pcVar17;
        if (plVar19 == (longlong *)0x0) {
LAB_23e7f4a80:
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          uVar26 = 0xe8;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7f39f0;
        }
        iVar10 = FUN_23a35f020(plVar19);
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          (**(code **)(plVar19[1] + 0x30))();
        }
        if (iVar10 == -1) goto LAB_23e7f4a80;
        if (iVar10 == 0) {
          plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde80);
          if (plVar19 != (longlong *)0x0) {
            plVar20 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeddec0);
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))();
            }
            if (plVar20 != (longlong *)0x0) {
              *(undefined4 *)(plVar8 + 5) = 0xe9;
              plVar19 = (longlong *)FUN_23e91a870(param_1);
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
              if (plVar19 != (longlong *)0x0) {
                *plVar19 = *plVar19 + -1;
                if (*plVar19 == 0) {
                  FUN_23a334bc0(plVar19);
                }
                goto LAB_23e7f5515;
              }
            }
          }
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar26 = 0xe9;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7f39f0;
        }
LAB_23e7f5515:
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        uVar16 = DAT_23eedde28;
        *(undefined4 *)(plVar8 + 5) = 0xe5;
        plVar19 = (longlong *)FUN_23e957a30(param_1,plVar14,uVar16);
        if (plVar19 == (longlong *)0x0) {
          auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar22 = *(code **)(param_1 + 0x68);
          pcVar17 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          iVar10 = 0xe5;
          *(undefined8 *)(param_1 + 0x70) = 0;
          goto LAB_23e7f3df7;
        }
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          FUN_23a334bc0(plVar19);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          FUN_23a334bc0(plVar12);
        }
        lVar11 = *plVar18;
        *plVar18 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          FUN_23a334bc0(plVar18);
        }
        lVar11 = *plVar14;
        *plVar14 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
LAB_23e7f522a:
        lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar12 = *(longlong **)(lVar11 + 0x28);
        plVar8 = (longlong *)plVar12[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
        *(undefined4 *)(plVar12 + 8) = 0xffffffff;
        if (plVar8 != (longlong *)0x0) {
          plVar12[2] = 0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))();
          }
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plVar12[0xf] = 0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        goto LAB_23e7f4f2e;
      }
      *(undefined4 *)(plVar8 + 5) = 0xe5;
      plVar20 = (longlong *)FUN_23e957a30(param_1,plVar14,DAT_23eedde28);
      if (plVar20 == (longlong *)0x0) {
        pcVar17 = *(code **)(param_1 + 0x70);
        auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        iVar10 = 0xe5;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e7f3df7;
      }
LAB_23e7f4087:
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))();
      }
LAB_23e7f4094:
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde70);
      if (plVar12 == (longlong *)0x0) {
LAB_23e7f4e10:
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e7f4e4b:
        if (apcStack_88[0] != (code *)0x0) {
          uVar26 = 0xeb;
          plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
          goto joined_r0x00023e7f507b;
        }
LAB_23e7f5201:
        uVar26 = 0xeb;
        goto LAB_23e7f4b70;
      }
      *(undefined4 *)(plVar8 + 5) = 0xeb;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23eeddf40);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e7f4e10;
      iVar10 = FUN_23a35f020(plVar14);
      lVar11 = *plVar14 + -1;
      if (iVar10 == -1) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = lVar11;
        if (lVar11 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
          goto joined_r0x00023e7f4e4b;
        }
        if (apcStack_88[0] == (code *)0x0) goto LAB_23e7f5201;
        uVar26 = 0xeb;
        plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
        goto joined_r0x00023e7f507b;
      }
      *plVar14 = lVar11;
      if (lVar11 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      pcVar17 = _Py_NoneStruct_exref;
      if (iVar10 != 0) {
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        goto LAB_23e7f522a;
      }
      lVar11 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar11 + 0x28) + 0x160) != 0) || (*(int *)(lVar11 + 0x78) != 0))
          && (iVar10 = Py_MakePendingCalls(), iVar10 < 0)) &&
         (pcVar17 = *(code **)(param_1 + 0x60), pcVar17 != (code *)0x0)) goto LAB_23e7f42af;
      if (*(int *)(lVar11 + 0x68) == 0) {
        plVar12 = *(longlong **)(param_1 + 0x90);
      }
      else {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar12 = *(longlong **)(param_1 + 0x90);
      }
    } while (plVar12 == (longlong *)0x0);
    plVar14 = *(longlong **)(param_1 + 0x60);
    plVar18 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar19 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar12;
    *plVar12 = *plVar12 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    pcVar17 = *(code **)(param_1 + 0x60);
LAB_23e7f42af:
    apcStack_88[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_90 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    auStack_98 = (undefined1  [8])pcVar17;
    if (apcStack_88[0] != (code *)0x0) {
      uVar26 = 0xe2;
      plVar12 = *(longlong **)(apcStack_88[0] + 0x18);
joined_r0x00023e7f507b:
      pcVar17 = apcStack_88[0];
      if (plVar8 == plVar12) goto LAB_23e7f4624;
      goto LAB_23e7f4570;
    }
    uVar26 = 0xe2;
    apcStack_88[0] = (code *)0x0;
  }
LAB_23e7f4b70:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar15 = apcStack_88[0];
  }
  else {
    pcVar15 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar15;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar15 = (code *)0x0;
  }
  pcVar22 = _PyRuntime_exref;
  *(longlong **)(pcVar17 + 0x18) = plVar8;
  *(longlong *)(pcVar17 + 0x10) = 0;
  *plVar8 = *plVar8 + 1;
  lVar11 = *(longlong *)(pcVar22 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x24) = uVar26;
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
  lVar21 = *(longlong *)(pcVar17 + -8);
  puVar3 = *(undefined8 **)(lVar11 + 8);
  *puVar3 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar11;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
  *(code **)(lVar11 + 8) = pcVar17 + -0x10;
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
  }
LAB_23e7f4624:
  apcStack_88[0] = pcVar17;
  FUN_23e8bba40(plVar8,"ooooo",plVar1,plVar2,plVar13,pcVar25,pcStack_f0);
  if (_DAT_23eedea90 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eedea90 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar11 + 0x28);
  plVar8 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  pcVar15 = apcStack_88[0];
  pcVar17 = pcStack_90;
  auVar28 = auStack_98;
  plVar12[0xf] = 0;
  _auStack_98 = (undefined1  [16])0x0;
  apcStack_88[0] = (code *)0x0;
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((pcVar25 != (code *)0x0) &&
     (*(longlong *)pcVar25 = *(longlong *)pcVar25 + -1, *(longlong *)pcVar25 == 0)) {
    (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
  }
  if ((pcStack_f0 != (code *)0x0) &&
     (*(longlong *)pcStack_f0 = *(longlong *)pcStack_f0 + -1, *(longlong *)pcStack_f0 == 0)) {
    (**(code **)(*(longlong *)(pcStack_f0 + 8) + 0x30))(pcStack_f0);
  }
  _auStack_98 = CONCAT88(pcVar17,auVar28);
  *plVar1 = *plVar1 + -1;
  apcStack_88[0] = pcVar15;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_98,pcStack_90,apcStack_88[0]);
  return (code *)0x0;
}
